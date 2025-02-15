class Solution {
public:
    unordered_map<string,vector<string>> graph;
    unordered_map<string,int>vis;
    void dfs(string s,vector<string> &v){
        vis[s]=1;
        v.push_back(s);
        for(auto it:graph[s]){
            if(vis[it]==1)continue;
            dfs(it,v);
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& ac) {
        for(int i=0;i<ac.size();i++){
            for(int j=1;j<ac[i].size()-1;j++){
                graph[ac[i][j]].push_back(ac[i][j+1]);
                graph[ac[i][j+1]].push_back(ac[i][j]);
                vis[ac[i][j]]=0;
                vis[ac[i][j+1]]=0;
            }
        }
        vector<vector<string>>ans;
        for(int i=0;i<ac.size();i++){
            if(vis[ac[i][1]]==0){
                vector<string>v;
                v.push_back(ac[i][0]);
                dfs(ac[i][1],v);
                sort(++v.begin(),v.end());
                ans.push_back(v);
            }
        }
        return ans;
    }
};