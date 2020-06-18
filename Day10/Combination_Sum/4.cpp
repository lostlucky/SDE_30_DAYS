class Solution {
    
    vector<int>dp;
    
    int f(int target, vector<int>& nums){
        if(target < 0) return 0;
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];
        dp[target] = 0;
        for(auto x:nums) dp[target] += f(target - x, nums);
        return dp[target];
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target + 1, -1);
        return f(target, nums);
    }
};
