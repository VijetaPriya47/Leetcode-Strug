class Solution {
public:
//Iterative DP
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;

        vector<int> buy(k, INT_MIN);
        vector<int> sell(k, 0);

        for (auto it : prices) {
            for (int i = 0; i < k; i++) {
                if (i == 0)
                    buy[i] = max(buy[i], -it);
                else
                    buy[i] = max(buy[i], sell[i - 1] - it);
                sell[i] = max(sell[i], buy[i] + it);
            }
        }
        return sell[k - 1];
    }
};