class Solution {
    
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1;i <= amount;i++){
            for(auto x:coins){
                if(i - x < 0 or dp[i - x] == INT_MAX) continue;
                dp[i] = min(1 + dp[i - x], dp[i]);
            }
        }
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};
