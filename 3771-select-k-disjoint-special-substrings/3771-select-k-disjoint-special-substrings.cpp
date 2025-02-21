class Solution {
public:
    static bool custom(const pair<int,int>&a, const pair<int,int>&b){
        return a.second<b.second;
    }
    bool maxSubstringLength(string s, int k) {
        if(k==0)return true;
        int n=s.size();
        cout<<n;

        vector<int>start(26,n+1),last(26,-1);
        for(int i=0;i<n;i++){
            int chr=s[i]-'a';
            start[chr]=min(i,start[chr]);
            last[chr]=max(i,last[chr]);
        }

        vector<pair<int,int>>segments;

        for(int i=0;i<n;i++){
            // cout<<1;
            int chr=s[i]-'a';
            // cout<<i<<start[chr];
            if(i!= start[chr]){
                continue;
            }
            // cout<<1;

            int far = last[chr];
            int curr = i;
            bool isValid = true;
            // cout<<i<<far;
            while(curr< far){
                if(start[s[curr]-'a']<i){
                    isValid=false;
                    break;
                }

                far=max(far,last[s[curr]-'a']);
                curr++;
            }
            // cout<<i<<far;
            if (isValid && !(i==0 && far==n-1)){
                cout<<i<<" "<<far<<" ";
                segments.emplace_back(i,far);
                //Emplace Black is used for when when you don't 
                //want copies to be made of pair<int,int> in this case.
            }
        }

        sort(segments.begin(),segments.end(), custom);

        cout<<segments.size();
        int segCnt=0, lastInd = -1;
        for (const auto & bound:segments){

            if(bound.first > lastInd){
                segCnt++;
                lastInd = bound.second;
            }
        }
        cout<<segCnt;
        return segCnt >= k;
    }
};