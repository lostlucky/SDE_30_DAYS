class Solution {
    
    vector<vector<int>>dp;
    
    vector<vector<int>>palin;
    
    void calPalin(int left, int right, string& s){
        while(left >= 0 and right < s.size()){
            palin[left][right] += (s[left] != s[right]) + (left < right - 1 ? palin[left + 1][right - 1] : 0);
            left--, right++;
        }
    }
    
    int f(int i,int k,string& s){
        if(k < 0) return INT_MAX;
        if(i == s.size()) return k == 0 ? 0 : INT_MAX;
        if(dp[i][k] != -1) return dp[i][k];
        dp[i][k] = INT_MAX;
        int val;
        for(int j = i;j < s.size();j++){
            val = f(j + 1, k - 1, s);
            if(val == INT_MAX) continue;
            dp[i][k] = min(dp[i][k], palin[i][j] + val);
        }
        return dp[i][k];
    }
    
public:
    int palindromePartition(string s, int k) {
        
        palin.resize(s.size(),vector<int>(s.size(), 0));
        
        for(int i = 0;i < s.size();i++){
            calPalin(i,i,s);
            calPalin(i,i + 1,s);
        }
        dp.resize(s.size(), vector<int>(k + 1, -1));
        return f(0,k,s);
    }
};
