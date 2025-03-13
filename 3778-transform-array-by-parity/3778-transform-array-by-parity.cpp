class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n=nums.size();
        int st=0;int end=n-1;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]%2==1){
                ans[end]=1;
                end--;
            }
        }
        return ans;
    }
};