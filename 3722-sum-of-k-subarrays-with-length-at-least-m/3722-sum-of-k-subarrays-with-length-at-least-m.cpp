#define ll long long
class Solution {
public:
    int maxSum(vector<int>& arr, int k, int m) {
        int n=arr.size();
        vector<ll>pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+arr[i];
        }

        const ll min=-1e18;
        vector<vector<ll>>dp(arr.size()+1,vector<ll>(k+1,min));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }

        for(int j=1;j<=k;j++){
            ll mini=min;
            for(int i=j*m;i<=n;i++){
                if(i-m>=0){
                    mini=max(mini,dp[i-m][j-1]-pre[i-m]);
                }
                dp[i][j]=max(dp[i-1][j],pre[i]+mini);
            }
        }
        return dp[n][k];
    }
};