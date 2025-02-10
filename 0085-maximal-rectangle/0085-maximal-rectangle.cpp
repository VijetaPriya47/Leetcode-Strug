class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<int>heights(m+1,0);

        int mxarea=0;

        for(int i=0;i<n;i++){ 
            for(int j=0;j<m;j++){
                heights[j]=(mat[i][j]=='1')? heights[j]+1:0;
            }

            
            for(int j=0;j<m;j++){
                int mh=heights[j];
                for(int k=j;k<m;k++){
                        if(heights[k]==0){
                            // cout<<1;
                            break;
                        }
                        mh=min(heights[k],mh);
                        mxarea=max(mxarea,mh*(k-j+1));
                        // cout<<mh;
                } 
            }
        }
        return mxarea;
    }
};