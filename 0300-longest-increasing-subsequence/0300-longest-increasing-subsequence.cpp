class Solution {
public:
    int rec(vector<int>nums, int last,int ind,vector<vector<int>> dp){
        if(ind==nums.size()){
            return 0;
        }

        
        if( dp[ind][last+1]!=-1){
            return dp[ind][last+1];
        }

        //Take
        int take=0;
        if(last==-1 || nums[ind]>nums[last])
            take=1+rec(nums,ind,ind+1,dp);

        //Nottake
        int nttake=rec(nums,last,ind+1,dp);

        return dp[ind][last+1]=max(take,nttake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // nums.insert(nums.begin(),-10001);
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        // dp[0][0]=0;
        return rec(nums,-1,0,dp);
        
    }
};