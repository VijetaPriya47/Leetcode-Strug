class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& ed, int dis) {
        vector<vector<int>>mat(n,vector<int>(n,1e9+1));
        for(int i=0;i<ed.size();i++){
            mat[ed[i][0]][ed[i][1]]=ed[i][2];
            mat[ed[i][1]][ed[i][0]]=ed[i][2];

        }
        for(int i=0;i<n;i++)mat[i][i]=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][k]!=1e9+1 && mat[k][j]!=1e9+1)
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }

        int ans=0;
        int mn=n+2;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i!=j)
                if(mat[i][j]<=dis){
                    cnt++;
                }
            }
            if(cnt==mn){
                ans=max(ans,i);
            }
            if(cnt<mn){
                // cout<<i;
                mn=min(mn,cnt);
                ans=i;
            }
        }

        return ans;
    }
};