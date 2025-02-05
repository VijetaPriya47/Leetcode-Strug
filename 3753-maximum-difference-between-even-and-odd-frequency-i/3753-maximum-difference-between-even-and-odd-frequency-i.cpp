class Solution {
public:
    int maxDifference(string s) {
        map<char,int>mp;
        for(auto x:s)mp[x]++;

        int mx=0,mn=s.size()+1;
        for(auto [x,y]:mp){
            if(y%2){
                //odd
                mx=max(mx, y);
            }
            else{
                ///even
                mn=min(mn,y);
            } 
        }
        if(mn==s.size()+1){
            mn==0;
        }
        return mx-mn;
    }
};