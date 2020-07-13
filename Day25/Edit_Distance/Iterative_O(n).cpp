class Solution {
public:
    
    int minDistance(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if(m < n) swap(m, n), swap(s1, s2);
        vector<vector<int>>dp(2, vector<int>(n + 1));
        for(int j = 0;j <= n;j++) dp[0][j] = j;
        for(int i = 1;i <= m;i++){
            dp[1][0] = i;
            for(int j = 1;j <= n;j++){
                if(s1[i - 1] == s2[j - 1]) dp[1][j] = dp[0][j - 1];
                else dp[1][j] = 1 + min({dp[0][j - 1], dp[0][j], dp[1][j - 1]});
            }
            dp[0] = dp[1];
        }
        
        return dp[0][n];
    }
};
