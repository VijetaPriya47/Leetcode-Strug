class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        map<int,vector<int>>mp;
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]].push_back(i);
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum=0;
        vector< long long>ans(nums1.size());
        for(auto & i:mp){
            int temp = sum;
            for(auto  & j:i.second){
                ans[j]=sum;
            }
            for(auto & j:i.second){
                sum+=nums2[j];
                pq.push(nums2[j]);
                if(pq.size()>k){
                    sum-=pq.top();
                    pq.pop();
                }
            }
        }
        return ans;
        
    }
};