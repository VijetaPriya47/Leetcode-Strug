class Solution {
public:
    int countArrays(vector<int>& og, vector<vector<int>>& bd) {
        int n=og.size();
        // vector<pair<int,int>>vec(n);
        // for(int  i=0;i<n;i++){
        //     vec[i].first=bd[i][1]-bd[i][0]+1;
        //     vec[i].second=i;
        // }
        // sort(vec.begin(), vec.end());
        int st=bd[0][0];int end=bd[0][1];
        for(int i=1;i<n;i++){
            int diff=og[i]-og[i-1];
            st=max(st+diff,bd[i][0]);
            end=min(end+diff,bd[i][1]);
            if(end<st)return 0;
        }
        return end-st+1;
    }
};