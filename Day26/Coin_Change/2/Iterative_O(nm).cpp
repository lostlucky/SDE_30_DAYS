class Solution {

public:
    int change(int amount, vector<int>& coins) {
        if(!coins.size()) return amount == 0;
        int n = coins.size();
        vector<vector<int>>dp(amount + 1, vector<int>(n + 1));
        dp[0][0] = 1;
        for(int j = 1;j <= n;j++){
            dp[0][j] = 1;
            for(int i = 0;i <= amount;i++){
                dp[i][j] = dp[i][j - 1] + (i >= coins[j - 1] ? dp[i - coins[j - 1]][j] : 0);
            }
        }
        
        return dp[amount][n];
    }
};
