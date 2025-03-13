// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

class Solution {
public:
    vector<PII> g[100005];
    LL mx[200005];
    
    long long maxSubarrays(int n, vector<vector<int>>& c) {
        int m = c.size();
        for (int i = 0; i < m; i++) {
            int l = c[i][0], r = c[i][1];
            if (l > r) swap(l, r);
            //l++, r++;
            g[r].pb(mp(l, i + 1));
        }
        LL s = 0;
        LL m1 = 0, m2 = 0;
        int p1 = 0;
        for (int i = 1; i <= n; i++) {
            for (PII o: g[i]) {
                if (o.fi >= m1) {
                    m2 = m1;
                    m1 = o.fi;
                    p1 = o.se;
                } else if (o.fi >= m2) {
                    m2 = o.fi;
                }
            }
            s += i - m1;
            if (m1 > m2) {
             //   cout << i << " " << p1 << "??" << m1 << " " << m2 <<endl;
                mx[p1] += m1 - m2;
            }
        }
       // cout << s << endl;
        LL ans = 0;
        for (int i = 1; i <= m; i++)
            chkMax(ans, mx[i]);
        return ans + s;
    }
};