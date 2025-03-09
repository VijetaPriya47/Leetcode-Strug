class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        // sort(f.begin(),f.end());
        int cnt=0;
        for(int j=0;j<f.size();j++){

        for(int i=0;i<b.size();i++){
            if(b[i]!=-1 && f[j]<=b[i]){
                cnt++;
                b[i]=-1;
                break;
            }
        }
        }
        return f.size()-cnt;
        
    }
};