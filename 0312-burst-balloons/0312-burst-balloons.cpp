class Solution {
public:

//For recursion: 
// We are using a bottom top approach, and going such that what if Kth baloon has been burst last.
// Exponential time complexity

//For Memoization:
// Use DP to store ans to dp[i][k-1] in recursion if has done before, then take it's value;

//For Tabulation:
    int maxCoins(vector<int>& nums) {
            int n = nums.size();
            
            nums.insert(nums.begin(), 1);
            nums.push_back(1);
            
            vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

// It's basically doing the same thing just using this i andd j to get 
// the smallest index it can have to start the option 
// This is Bottom-UPs approach (interval DP)
// Consider each balloon as the last one to burst in a rang
            for (int i = n; i >= 1; i--) {
                for (int j = 1; j <= n; j++) {
                    if (i > j) continue;
                    int maxi = INT_MIN;
                    

                    for (int ind = i; ind <= j; ind++) {
                        int coins = nums[i - 1] * nums[ind] * nums[j + 1];

                        int remainingCoins = dp[i][ind - 1] + dp[ind + 1][j];
                        
                        maxi = max(maxi, coins + remainingCoins);
                    }
                    
                    dp[i][j] = maxi;
                }
            }
            
            return dp[1][n];
    }
};