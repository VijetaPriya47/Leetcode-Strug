class Solution {
public:
    vector<vector<vector<int>>> dp;
//Recursive DP
    int solve(int k, int i, vector<int>& prices, bool canBuy) {
        if (i == prices.size() || k == 0)
            return 0;

        if (dp[i][k][canBuy] != -1)
            return dp[i][k][canBuy];

        if (canBuy) {
            return dp[i][k][canBuy] =
                       max(-prices[i] + solve(k, i + 1, prices, !canBuy),
                           solve(k, i + 1, prices, canBuy));
        }

        return dp[i][k][canBuy] =
                   max(prices[i] + solve(k - 1, i + 1, prices, !canBuy),
                       solve(k, i + 1, prices, canBuy));
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp.resize(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return solve(k, 0, prices, true);
    }
};