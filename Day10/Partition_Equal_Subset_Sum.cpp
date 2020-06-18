class Solution {
public:
    vector<vector<int>>dp;
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x:nums) sum += x;
        if(sum % 2) return 0;
        dp.resize(nums.size(),vector<int>(sum / 2 + 1,-1));
        return f(0,sum / 2,nums);
    }
    
    bool f(int i,int sum,vector<int>& nums){
        if(sum == 0) return 1;
        if(i == nums.size()) return 0;
        if(sum < 0) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        return dp[i][sum] = f(i + 1,sum,nums) or f(i + 1,sum - nums[i],nums);
    }
};
