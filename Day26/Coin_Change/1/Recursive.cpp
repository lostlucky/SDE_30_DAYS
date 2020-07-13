class Solution {
    
    vector<int>dp;
    
    int f(int n,vector<int>&coins){
        if(n < 0) return INT_MAX;
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        dp[n] = INT_MAX;
        for(auto x:coins){
            int val = f(n - x, coins);
            if(val == INT_MAX) continue;
            dp[n] = min(dp[n], val + 1);
        }
        return dp[n];
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount + 1, -1);
        int ans = f(amount, coins);
        return ans != INT_MAX ? ans : -1;
    }
};
