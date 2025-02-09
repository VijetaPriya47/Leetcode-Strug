class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int dp[301][301];
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    if(i-1>=0 && j-1>=0){
                     
                        dp[i][j]=min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                    }
                        dp[i][j]++;
                        cout<<dp[i][j];
                        ans+=dp[i][j];
            
                }
            }
                cout<<endl;

        }
        return ans;
    }
};