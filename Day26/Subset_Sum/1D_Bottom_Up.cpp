// ****    The reason for reverse iteration of w is so that the previously set state in the same number do not interfare with the to be calculated states   **** //

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1) return 0; 
        sum /= 2;
        vector<int>dp(sum + 1);
        dp[0] = 1;
        for(auto num:nums){
            for(int w = sum;w >= num;w--){
                dp[w] |= dp[w - num];
            }
        }
        return dp[sum];
    }
};
