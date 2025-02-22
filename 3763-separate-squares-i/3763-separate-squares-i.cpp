class Solution {
public:
    double helper(double line, vector<vector<int>>& sq){
        double aA=0, aB=0;
        int n=sq.size();
        for(int i=0; i<n; i++){
            int x = sq[i][0];
            int y = sq[i][1];
            int l = sq[i][2];
            double total= (double)l*l;

            if(line<=y){
                aA+=total;
            }
            else if(line>=y+l){
                aB+=total;
            }
            else{
                //The line intersects the square.
                double abheight = (y+l) - line;
                double beheight = (line - y);
                aA += abheight*l;
                aB += beheight*l;
            }
        }
        return aA - aB;
    }
    double separateSquares(vector<vector<int>>& sq) {
        int N=sq.size();
        double lo=0;
        double hi=2*1e9;

        //U can use While Loop but 
        //thee iterations are also good
        //I mean, how much high can it go?

        //So, it's a trade between Double Binary Search (ONe for int, one for decimal)
        //Or use toleration Values
        //For that use iiterations.
        for(int i=0;i<60;i++){
            double mid= (lo+hi)/2.0;
            double diff = helper(mid,sq);

            if(diff > 0) lo=mid;
            else hi = mid;
        }
        return hi;
    }
};