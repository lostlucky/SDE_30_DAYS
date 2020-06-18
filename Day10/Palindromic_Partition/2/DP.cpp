class Solution {
    
    vector<int>dp;
    vector<vector<int>>palin;
    
    int f(int i,string& s){
        if(i == s.size()) return -1;
        if(dp[i] != -1) return dp[i];
        string aux;
        dp[i] =  INT_MAX;
        for(auto nextIndex:palin[i]) dp[i] = min(dp[i], 1 + f(nextIndex, s));
        return dp[i];
    }
    
    void calPalin(int left, int right, string& s){
        while(left >= 0 and right < s.size() and s[left] == s[right]){
            palin[left].push_back(right + 1);
            left--, right++;
        }
    }
    
public:
    int minCut(string s) {
        if(!s.size()) return 0;
        dp.resize(s.size(), -1);
        palin.resize(s.size());
        for(int i = 0;i < s.size();i++){
            calPalin(i,i,s);
            calPalin(i, i + 1,s);
        }
        return f(0,s);
    }
};
