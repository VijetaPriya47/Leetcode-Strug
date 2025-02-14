class Solution {
public:
    int minDistance(string w1, string w2) {
        int n = w1.size(), m = w2.size();
        vector<vector<int>> dp(n + 1,
                               vector<int>(m + 1, 0)); // Initialize
                            //    with 0

        // Build the DP table iteratively
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (w1[i - 1] == w2[j - 1]) {
                    // Characters match, move diagonally
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // Characters don't match, take the max of excluding
                    // either
                    // character
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return  n + m - 2 *dp[n][m];
    }
};