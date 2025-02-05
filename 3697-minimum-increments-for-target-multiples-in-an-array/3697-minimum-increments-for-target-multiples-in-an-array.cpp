class Solution {
public:
    long long gcd(long long x, long long y){
        if(x % y == 0) return y;
        return gcd(y, x % y);
    }
    int minimumIncrements(vector<int>& nums, vector<int>& target) {
        int n=nums.size();
        int m=target.size();
        vector<long long >lcm(1<<m,0);
        for(int i=0;i<(1<<m);i++){
            long long now=1;
            for(int j=0;j<m;j++){
                if(i & (1<<j)){
                    now=(now*target[j])/gcd(now,target[j]);
                }
            }
            lcm[i]=now;
        }

        vector<vector<long long>> dp(n+1,vector<long long>(1<<m,1e18));

        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<(1<<m);j++){
                for(int k=0;k<(1<<m);k++){
                    if(nums[i-1]%lcm[k]==0) 
                        dp[i][j|k]=min(dp[i][j|k],dp[i-1][j]);
                    
                    else 
                        dp[i][j|k]=min(dp[i][j|k],dp[i-1][j]+lcm[k]-nums[i-1]%lcm[k]);
                    
                }
            }
        }
        return dp[n][(1<<m)-1];
    }
};