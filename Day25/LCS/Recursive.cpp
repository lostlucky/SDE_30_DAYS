class Solution {
    vector<vector<int>>dp;
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        dp.resize(m, vector<int>(n, -1));
        return f(0, 0,text1,text2);
    }
    
    int f(int i,int j,string& s1,string& s2){
        if(i == s1.size() or j == s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = (s1[i] == s2[j]) ? 1 + f(i + 1,j + 1,s1,s2) : max(f(i + 1, j, s1, s2), f(i, j + 1, s1, s2));
    }
};
