class Solution {
public:
// Always know the importance of &
// because the stack space is too much increasing
// and it will give you a memory limit exceeded
    int rec( int ind,int last,vector<int> &nums,vector<vector<int>> &dp){
        if(ind==nums.size()){
            return 0;
        }

        
        if( dp[ind][last+1]!=-1){
            return dp[ind][last+1];
        }

        //Take
        int take=0;
        if(last==-1 || nums[ind]>nums[last])
            take=1+rec(ind+1,ind,nums,dp);

        //Nottake
        int nttake=rec(ind+1,last,nums,dp);

        return dp[ind][last+1]=max(take,nttake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return rec(0,-1,nums,dp);
        
    }
};