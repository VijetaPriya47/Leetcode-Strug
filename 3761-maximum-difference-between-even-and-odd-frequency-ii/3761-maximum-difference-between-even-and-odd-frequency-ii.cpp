class Solution {
public:
    const int inf =1e9;
    int pre[5][30001];
    int pari[30001];
    int parj[30001];
    int cntd[30001];
    int maxDifference(string s, int k) {
        int n=s.size();
        vector<int>a(n+1,0);

        //Prefix Sum
        for(int i=1;i<=n;i++){
            a[i]=s[i-1]-'0';
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=4;j++){
                pre[j][i]=pre[j][i-1];
            }
            pre[a[i]][i]++;
        }

        int ans= - inf;

        //Digit Pairs
        for(int i=0;i<=4;i++){
            for(int j=0;j<=4;j++){

                if(i==j) continue;

                int cnt[4]= {inf,inf,inf,inf}; //cnt of digits in subs
                int it=0; //For Sliding Window
                for(int ind=1; ind<=n; ind++){//index
                    while(ind-it>=k && pre[i][ind]>pre[i][it] && pre[j][ind]>pre[j][it]){
                        cnt[pari[it]*2 + parj[it]] = min(cnt[pari[it]*2 + parj[it]],cntd[it]);
                        it++;
                    }
                    //If the count of ith digit is even or odd
                    if(a[ind]==i) pari[ind]=pari[ind-1] ^ 1;
                    else pari[ind] = pari[ind-1];

                    //If the cnt of jth digit is even or odd
                    if(a[ind]==j) parj[ind]=parj[ind-1] ^ 1;
                    else parj[ind] = parj[ind-1];

                    cntd[ind] = cntd[ind-1] + (a[ind] == i )-(a[ind]==j);
                    ans = max(ans, cntd[ind] - cnt[(1-pari[ind])*2 + parj[ind]]);
                }
            }
        }
            return ans;

    }
};