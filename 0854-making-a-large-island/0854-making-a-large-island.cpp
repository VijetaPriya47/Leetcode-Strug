class Solution {
public:
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,+1};

    int dfs(int x,int y, vector<vector<int>>&vis,vector<vector<int>>&grid,int cnt){
        int n=grid.size();
        vis[x][y]=cnt;
        int dis=1;
        for(int i=0;i<4;i++){
            int newi=x+dx[i];
            int newj=y+dy[i];
            if(min(newi,newj)>=0 &&
                 max(newi,newj)<n &&
                 vis[newi][newj]==0 &&
                 grid[newi][newj]==1){

                dis+=dfs(newi,newj,vis,grid,cnt);
            }
        }
        return dis;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        // int m=grid[0].size();
        // vector<vector<int>>dis(n,vector<int>(n,0));
        vector<vector<int>>vis(n,vector<int>(n,0));
        unordered_map<int,int>mp;
        int cnt=0;
        int mx=0;
        // int dis=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    int dis=0;
                    cnt++;
                    vis[i][j]=cnt;
                    dis+=dfs(i,j,vis,grid,cnt);

                    mp[cnt]=dis;
                    // mx=max(dis,mx);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int dis=0;
                    unordered_set<int>s;
                    for(int k=0;k<4;k++){
                        int newi=i+dx[k];
                        int newj=j+dy[k];
                        if(min(newi,newj)>=0 &&
                            max(newi,newj)<n &&
                            // vis[newi][newj]==0 &&
                            grid[newi][newj]==1){
                            s.insert(vis[newi][newj]);
                        }
                    }
                    for(auto x:s){
                        dis+=mp[x];
                    }
                    // cout<<dis;
                    mx=max(mx,dis+1);
                }
            }
        }
        if(cnt==1 && mx==0)return n*n;
        return mx;

    }
};