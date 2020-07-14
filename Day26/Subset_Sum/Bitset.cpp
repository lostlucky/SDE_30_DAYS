class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<10001>dp = 1;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return 0;
        for(auto x:nums) dp |= (dp << x);
        return dp[sum / 2];
    }
};
