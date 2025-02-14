class Solution {
public:
int prime =1e9+7;
    int change(int W, vector<int>& c) {
        int n=c.size();
        uint64_t dp[5001];
        memset(dp,0,sizeof(dp));
        // Iterating over coins first ensures that order doesn’t matter, treating {1+2} and {2+1} as the same.
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=c[i];j<=W;j++){
                (dp[j]+=dp[j-c[i]]);
                // %=prime;
            
            }
        }
        return dp[W];
    }
};