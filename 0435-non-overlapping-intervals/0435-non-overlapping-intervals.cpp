class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inv) {
        int n=inv.size();
        sort(inv.begin(),inv.end(),[] (const auto&a, const auto & b){
            return a[1] < b[1];
        });

        int prev_end=inv[0][1];
        int res=0;

        for(int i=1;i<n;i++){
            if(inv[i][0]<prev_end){
                res++;
            }
            else{
                prev_end=inv[i][1];
            }
        }
        return res;
    }
};