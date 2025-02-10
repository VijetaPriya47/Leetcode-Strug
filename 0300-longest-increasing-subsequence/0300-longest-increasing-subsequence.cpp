class Solution {
public:
    int  rec(int lvl, int prev, vector<int>&arr, vector<vector<int>>& dp){
        if (lvl == arr.size()) {
            return 0; // At the end, the LIS length is 0
        }
        
        if (dp[lvl][prev+1] != -1) {
            return dp[lvl][prev+1]; // Return the stored result
        }

        // Case 1: Don't take the current element
        int notTake = rec(lvl + 1, prev, arr, dp);

        // Case 2: Take the current element (only if it forms an increasing subsequence)
        int take = 0;
        if (prev == -1 || arr[lvl] > arr[prev]) {
            take = 1 + rec(lvl + 1, lvl, arr, dp); // Increment length by 1 when taking the element
        }

        // Store the result in dp and return the max of taking or not taking the element
        return dp[lvl][prev+1] = max(take, notTake);
    }  
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return rec(0,-1,nums,dp);
        
    }
};