#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;

int f(int i,int j,vector<int>& nums){
    if(i + 2 > j) return 0;
    if(i + 2 == j) return nums[i] * nums[i + 1] * nums[i + 2];
    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    for(int k = i + 1;k <= j - 1;k++){
        ans = min(ans, nums[i] * nums[k] * nums[j] + f(i, k, nums) + f(k, j, nums));
    }
    return dp[i][j] = ans;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>nums(n);
        for(int i = 0;i < n;i++) cin >> nums[i];
        dp.clear();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        cout << f(0, n - 1, nums) << endl;
    }
	return 0;
}
