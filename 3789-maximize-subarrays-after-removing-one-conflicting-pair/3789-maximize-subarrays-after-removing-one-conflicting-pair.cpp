const int K = 25, MAXN = 1e5;
int st_min[K + 1][MAXN];
int st_max[K + 1][MAXN];

void build_min(auto& array) {
    std::copy(array.begin(), array.end(), st_min[0]);

    for(int i = 1; i <= K; i++)
        for(int j = 0; j + (1 << i) <= array.size(); j++)
            st_min[i][j] = min(st_min[i - 1][j], st_min[i - 1][j + (1 << (i - 1))]);
}
int query_min(int L, int R) {
    int i = bit_width(unsigned(R - L + 1)) - 1;
    return min(st_min[i][L], st_min[i][R - (1 << i) + 1]);
}

void build_max(auto& array) {
    std::copy(array.begin(), array.end(), st_max[0]);

    for(int i = 1; i <= K; i++)
        for(int j = 0; j + (1 << i) <= array.size(); j++)
            st_max[i][j] = max(st_max[i - 1][j], st_max[i - 1][j + (1 << (i - 1))]);
}
int query_max(int L, int R) {
    int i = bit_width(unsigned(R - L + 1)) - 1;
    return max(st_max[i][L], st_max[i][R - (1 << i) + 1]);
}

int bisect(int start, int end, int idx) {
    int L = start, R = end, Q = -1;
    while(L <= R) {
        int M = (L + R) / 2;
        if(query_max(start, M) <= idx && query_min(start, M) >= M) {
            Q = M;
            L = M + 1;
        }else {
            R = M - 1;
        }
    }
    return Q;
}

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<int> min_take(n, 0), max_take(n, n - 1);
        vector<vector<int>> conflicts(n);
        for(auto& p : conflictingPairs) {
            p[0]--, p[1]--;
            if(p[0] > p[1]) swap(p[0], p[1]);
            max_take[p[0]] = min(max_take[p[0]], p[1] - 1);
            min_take[p[1]] = max(min_take[p[1]], p[0] + 1);
            conflicts[p[1]].push_back(p[0]);
        }
        for(int i = 0; i < n; i++) {
            sort(conflicts[i].begin(), conflicts[i].end());
        }
        build_min(max_take);
        build_max(min_take);
        
        long long global = 0;
        unordered_map<int, long long> extra;
        for(int i = 0; i < n; i++) {
            int maxIdx = bisect(i, n - 1, i);
            // can always take until maxIdx with 0 conficts
            global += maxIdx - i + 1; 

            if(maxIdx + 1 == n) continue;
            // possibly take (maxIdx + 1) while violating only 1
            auto& con = conflicts[maxIdx + 1];
            auto it = lower_bound(con.begin(), con.end(), i);
            // if there are 2 conflicts: break
            if(next(it) != con.end() && i <= *next(it) && *next(it) <= maxIdx) {
                continue;
            }
            // expand more
            int furthest = max(bisect(maxIdx + 2, n - 1, i), maxIdx + 1);
            extra[((maxIdx + 1) << 16) | *it] += furthest - maxIdx;
        }
        long long best_extra = 0;
        for(const auto& p : extra) {
            best_extra = max(best_extra, p.second);
        }
        return global + best_extra;
    }
};