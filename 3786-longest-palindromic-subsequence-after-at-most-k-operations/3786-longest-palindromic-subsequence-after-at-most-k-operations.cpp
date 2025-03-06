class Solution {
public:
    vector<vector<vector<int>>>dp;
    int mini(char  &a, char & c){
        return min(26-abs(a-c),abs(a-c));
    }
    int solve(int i, int j, string &s, int k){
        if(i>j)return 0;
        if(i==j)return 1;
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        if(s[i]==s[j])return dp[i][j][k]=2+solve(i+1,j-1,s,k);
        int ans=max(solve(i+1,j,s,k),solve(i,j-1,s,k));
        int diff=mini(s[i],s[j]);
        // cout<<diff;
        if(diff<=k){
            ans=max(ans, 2 +solve(i+1,j-1,s,k-diff));
        }
        return dp[i][j][k]=ans;
    }
    int longestPalindromicSubsequence(string s, int k) {
        int n=s.size();
        dp.resize(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return solve(0,n-1,s,k);
    }
};