class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>v(amount+1);
        for(int i=0;i<n;i++){
            v[0] = 0;
        }
        for(int i=0;i<=amount;i++){
            if(i % coins[0] == 0){
                v[i] = i / coins[0];
            }
            else{
                v[i] = 1e9;
            }
        }
        for(int i=1;i<n;i++){
            vector<int>curr(amount+1);
            for(int j=0;j<=amount;j++){
                int pick = 1e9;
                if(coins[i] <= j){
                    pick = 1+ curr[j-coins[i]];
                }
                int no_pick = v[j];
                curr[j] = min(pick,no_pick);
            }
            v = curr;
        }
        if(v[amount] >= 1e9)return -1;
        return v[amount];
    }
};