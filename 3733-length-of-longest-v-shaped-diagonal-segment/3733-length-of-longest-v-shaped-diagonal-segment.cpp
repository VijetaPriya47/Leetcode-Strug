class Solution {
public:
    int dirx[4]={-1,1,1,-1};
    int diry[4]={-1,-1,1,1};
    int ans=0;
    int n,m;
    int dp[501][501][2][2][4];
    int rec(int i, int j,int turn,int curr, int dir, vector<vector<int>>& grid){

        if(i>=n || j>=m || i<0 || j<0){
            return 0 ;
        }

        if(dp[i][j][turn][curr][dir]!=-1){
            return dp[i][j][turn][curr][dir];
        }

        if(curr && grid[i][j]!=2)return 0;
        if(!curr && grid[i][j]!=0)return 0;

        int xx=dir;
        int mx=0;

        // Turn (Clockwise)
        if(turn==0){
            xx=(dir+3)%4;
            mx=1+rec(i+dirx[xx],j+diry[xx],1,(curr+1)%2,xx,grid);
        }

        //No Turn
        xx=(dir);
        mx=max(mx,1+rec(i+dirx[xx],j+diry[xx],turn,(curr+1)%2,xx,grid));
 

        return dp[i][j][turn][curr][dir]=mx;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        ans=0;
        n=grid.size();
        m=grid[0].size();
        memset(dp , -1 ,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans=max(ans,1+rec(i+1,j+1,0,1,2,grid));
                    ans=max(ans,1+rec(i-1,j+1,0,1,3,grid));
                    ans=max(ans,1+rec(i+1,j-1,0,1,1,grid));
                    ans=max(ans,1+rec(i-1,j-1,0,1,0,grid));


                }
            }
        }
        return ans;
    }
};