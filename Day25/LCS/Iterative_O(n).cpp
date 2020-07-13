class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if(!m or !n) return 0;
        vector<vector<int>>dp(2, vector<int>(n + 1));
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                dp[1][j] = (s1[i - 1] == s2[j - 1]) ? 1 + dp[0][j - 1] : max(dp[0][j], dp[1][j - 1]);
            }
            dp[0] = dp[1];
        }
        return dp[0][n];
    }
};
