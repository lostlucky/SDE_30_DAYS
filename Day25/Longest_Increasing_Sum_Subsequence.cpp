#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>nums(n);
        for(int i = 0;i < n;i++) cin >> nums[i];
        vector<int>dp(n, 0);
        int ans = nums[0];
        dp[0] = nums[0];
        for(int i = 1;i < n;i++){
            dp[i] = nums[i];
            for(int j = i - 1;j >= 0;j--){
                if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + nums[i]);
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    
	return 0;
}
