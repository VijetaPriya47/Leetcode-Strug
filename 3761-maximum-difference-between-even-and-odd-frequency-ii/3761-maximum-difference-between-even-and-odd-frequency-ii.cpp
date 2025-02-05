class Solution {
public:
    const int inf = 1e9;
    int f[30005], g[30005], a[30005], h[30005];
    int q[5][30005];
    int maxDifference(string s, int k) {
        int n = s.size();
        for(int i = 1; i <= n; ++i) a[i] = s[i - 1] - '0';
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j <= 4; ++j){
                q[j][i] = q[j][i - 1];
            }
            q[a[i]][i]++;
        }
        int ans = -inf;
        for(int i = 0; i <= 4; ++i)
            for(int j = 0; j <= 4; ++j){
                if(i == j) continue;
                int mi[4] = {inf, inf, inf, inf}, it = 0;
                for(int l = 1; l <= n; ++l){
                    while(l - it >= k && q[i][l] > q[i][it] && q[j][l] > q[j][it]){
                        mi[f[it] * 2 + g[it]] = std::min(mi[f[it] * 2 + g[it]], h[it]);
                        ++it;
                    }
                    if(a[l] == i) f[l] = f[l - 1] ^ 1;
                    else f[l] = f[l - 1];
                    if(a[l] == j) g[l] = g[l - 1] ^ 1;
                    else g[l] = g[l - 1];
                    h[l] = h[l - 1] + (a[l] == i) - (a[l] == j);
                    ans = std::max(ans, h[l] - mi[(1 - f[l]) * 2 + g[l]]);
                }
            }
        return ans;
    }
};