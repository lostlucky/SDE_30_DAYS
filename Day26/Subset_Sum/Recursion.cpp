class Solution {
    
    vector<vector<int>>dp;
    bool f(int i, int total,vector<int>& nums){
        if(total < 0 or i == nums.size()) return 0;
        if(total == 0) return 1;
        if(dp[i][total] != -1) return dp[i][total];
        return dp[i][total] = f(i + 1, total - nums[i], nums) or f(i + 1, total, nums);
    }
    
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1) return 0;
        dp.resize(n, vector<int>(sum / 2 + 1, -1));
        return f(0, sum / 2, nums);
    }
};
