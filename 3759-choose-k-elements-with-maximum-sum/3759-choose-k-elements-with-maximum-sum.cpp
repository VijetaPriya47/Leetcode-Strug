class Solution {
public:
    vector<long long> findMaxSum(vector<int>& n1, vector<int>& n2, int k) {
        int n=n1.size();

        // vector<pair<int,int>>vec(n,pair<int,int>());
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[n1[i]].push_back(i);
        }

        priority_queue<int, vector<int>,greater<int>>pq;
        vector<long long>ans(n,0);
        long long result=0;
        for(auto [x,y]:mp){

            while(pq.size()>k){
                    result-=pq.top();
                    pq.pop();
            }
            long long sum=0;
            for(auto xx:y){
                ans[xx]+=result;
                pq.push(n2[xx]);
                sum+=n2[xx];
            }
            result+=sum;
        }
        return ans;
    }
};