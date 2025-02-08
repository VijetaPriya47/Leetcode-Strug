class Solution {
public:
    int maxFreeTime(int eve, int k, vector<int>& st, vector<int>& et) {

        int lo=0,hi=0;
        int end=0;

        int tt=0;
        st.push_back(eve);
        et.push_back(eve);
        int ans=0;

        while(hi<st.size()-1){
            if(hi-lo<k){
                tt+=et[hi]-st[hi];
                hi++;
            }
            else{
                tt-=(et[lo]-st[lo]);
                end=et[lo];
                lo++;
                tt+=et[hi]-st[hi];
                hi++;

                
            }
            ans=max(ans,st[hi]-tt-end);
        }
        return ans;

    }
};