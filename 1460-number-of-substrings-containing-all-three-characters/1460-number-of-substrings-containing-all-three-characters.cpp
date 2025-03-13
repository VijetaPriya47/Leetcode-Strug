class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>bol(3,0);
        int left=0,result=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            bol[s[i]-'a']++;
            // cout<<bol[s[i]-'a']<<bol[0];
            while(bol[0]>0 && bol[1]>0 && bol[2]>0){
                // cout<<4;
                result+=n-i;
                bol[s[left]-'a']--;
                left++;
            }
        }
        return result;
    }
};