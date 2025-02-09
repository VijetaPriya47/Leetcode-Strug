class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        if(mat.empty()|| mat[0].empty()){
            return 0;
        }

        int rows=mat.size();
        int col=mat[0].size();

        vector<int> heights(col+1,0);
        int maxArea=0;

        for (const auto & row:mat){
            for (int i=0;i<col;i++){
                heights[i]=(row[i]=='1') ? heights[i]+1:0;
            }

            int n = heights.size();

            for(int i=0;i<n;i++){
                for(int j=i, minHeight = INT_MAX;j<n;j++){
                    minHeight = min(minHeight, heights[j]);
                    int area = minHeight * (j-i+1);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};