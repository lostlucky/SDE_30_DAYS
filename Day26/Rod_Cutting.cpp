
int f(int n, vector<int>& nums, vector<int>& dp){
    if(n == 0) return 0;
    if(n < 0) return INT_MIN;
    if(dp[n] != INT_MIN) return dp[n];
    for(auto num:nums){
        int val = f(n - num, nums, dp);
        if(val == INT_MIN) continue;
        dp[n] = max(dp[n], 1 + val);
    }
    return dp[n];
}

int main() {
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>nums(3, 0);
        for(int i = 0;i < 3;i++) cin >> nums[i];
        vector<int>dp(n + 1, INT_MIN);
        f(n, nums, dp);
        cout << (dp[n] == INT_MIN ? -1 : dp[n]) << endl;
    }
    
	return 0;
}
