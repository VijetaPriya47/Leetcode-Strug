class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int N = arr.size();
        int K = k + 1;

        vector<int> dp(K, 0);

        for (int start = N - 1; start >= 0; start--) {
            int currmax = 0;
            int end = min(N, start + k);

            for (int i = start; i < end; i++) {
                currmax = max(currmax, arr[i]);
                dp[start % K] = max(dp[start % K], dp[(i + 1) % K] + currmax * (i - start + 1));
            }
        }
        return dp[0];
    }
};
