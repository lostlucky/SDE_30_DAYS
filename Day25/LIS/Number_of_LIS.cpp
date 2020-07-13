class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        vector<pair<int,int>>dp(n, {1, 1});
        int LIS = 1, ans = 0;
        for(int i = 1;i < n;i++){
            for(int j = i - 1;j >= 0;j--){
                if(nums[i] <= nums[j]) continue;
                if(dp[i].first < dp[j].first + 1) dp[i].first = dp[j].first + 1, dp[i].second = dp[j].second;
                else if(dp[i].first == dp[j].first + 1) dp[i].second += dp[j].second;
            }
            if(dp[i].first > LIS) LIS = dp[i].first, ans = dp[i].second;
            else if(dp[i].first == LIS) ans += dp[i].second;
        }
        if(LIS == 1) return n;
        return ans;
    }
};
