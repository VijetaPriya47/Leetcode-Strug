class Solution {
public:
    int maxFreeTime(int eve, vector<int>& st, vector<int>& et) {
        int k=1;
      int lo=0,hi=0;
        int end=0;

        int tt=0;
        st.push_back(eve);
        et.push_back(eve);
        int n=st.size();

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
        cout<<ans;
        int mx=0;
        end=0;
        for(int i=1;i<st.size();i++){
            int md=et[i-1]-st[i-1];
            if(md<=mx){
                ans=max(ans,st[i]-end);
            }
            mx=max(mx,st[i-1]-end);
            end=et[i-1];
        }
        cout<<ans;

        mx=0;
        end=eve;
        for(int i=n-2;i>=-1;i--){
            int md=et[i+1]-st[i+1];
            if(md<=mx){
            if(i==-1)
                ans=max(ans,end-0);
            else
                ans=max(ans,end-et[i]);
            }
            mx=max(mx,end-et[i+1]);
            end=st[i+1];
            // cout<<mx;
        }
        
        return ans;
    }
};