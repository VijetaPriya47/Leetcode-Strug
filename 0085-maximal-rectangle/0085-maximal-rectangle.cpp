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

            stack<int>st;
            for(int j=0;j<m+1;j++){
                
                while(!st.empty() && heights[j]<heights[st.top()]){
                    int h=heights[st.top()];
                    st.pop();
                    int w=st.empty() ? j:j-st.top()-1;
                    mxarea=max(mxarea,h*w);
                }
                st.push(j);
                
            }
        }
        return mxarea;
    }
};