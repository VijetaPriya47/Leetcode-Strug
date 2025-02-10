class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    if(i>0 && j>0)
                        dp[i][j]=min({dp[i][j-1],dp[i-1][j-1],dp[i-1][j]});
                    dp[i][j]++;
                }
                ans+=dp[i][j];
            }
        }

        return ans;



        
    }
};