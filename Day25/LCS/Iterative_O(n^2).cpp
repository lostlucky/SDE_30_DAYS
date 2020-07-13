class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if(!m or !n) return 0;
        vector<vector<int>>dp(m + 1, vector<int>(n + 1));
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                dp[i][j] = (s1[i - 1] == s2[j - 1]) ? 1 + dp[i - 1][j - 1] : max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};
