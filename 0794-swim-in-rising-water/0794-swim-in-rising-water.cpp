class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({-grid[0][0],{0,0}});
        int xx[4]={+1,0,-1,0};
        int yy[4]={0,+1,0,-1};
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[0][0]=grid[0][0];
        
        while(!pq.empty()){
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            int dis=-pq.top().first;

            pq.pop();

            for(int k=0;k<4;k++){
                int nwi = x + xx[k];
                int nwj = y + yy[k];

                if(min(nwi, nwj)>=0 && max(nwi,nwj)<n){
                    int newdis=max(grid[nwi][nwj],dis);
                    if(dist[nwi][nwj]>newdis){
                        dist[nwi][nwj] = newdis;
                        pq.push({-newdis,{nwi,nwj}});
                    }
                }
            }
        }

        return dist[n-1][n-1];
    }
};