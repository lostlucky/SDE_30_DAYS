class Solution {
    unordered_map<int, vector<string>>dp;
    unordered_set<string>mp;
    
    vector<string> f(int i,string& s){
        if(i == s.size()) return {"#"};
        if(dp.count(i)) return dp[i];
        string sub;
        vector<string>ans;
        for(int j = i;j < s.size();j++){
            sub.push_back(s[j]);
            if(mp.count(sub)){
                f(j + 1, s);
                if(j + 1 == s.size()){
                    ans.push_back(sub);
                }
                else if(dp[j + 1][0] != "#"){
                    for(auto x:dp[j + 1]) ans.push_back(sub + " " + x);
                }
            }
        }
        if(!ans.size()) dp[i] = {"#"};
        else dp[i] = ans;
        return dp[i];
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto word:wordDict) mp.insert(word);
        f(0, s);
        vector<string>empty;
        return dp[0][0] == "#" ? empty : dp[0];
    }
};
