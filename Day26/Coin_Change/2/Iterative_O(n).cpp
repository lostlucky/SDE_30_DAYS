class Solution {

public:
    int change(int amount, vector<int>& coins) {
        if(!coins.size()) return amount == 0;
        vector<int>dp(amount + 1);
        dp[0] = 1;
        for(auto x:coins){
            for(int i = x;i <= amount;i++){
                dp[i] += dp[i - x];
            }
        }
        
        return dp[amount];
    }
};
