class Solution {
    vector<int>dp;
    unordered_set<string>mp;
    
    bool f(int i,string& s){
        if(i == s.size()) return 1;
        if(dp[i] != -1) return dp[i];
        string sub;
        for(int j = i;j < s.size();j++){
            sub.push_back(s[j]);
            if(mp.count(sub) and f(j + 1, s)) return dp[i] = 1;
        }
        return dp[i] = 0;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.size(), -1);
        for(auto word:wordDict) mp.insert(word);
        return f(0, s);
    }
};
