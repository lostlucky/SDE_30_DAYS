// Backtracking

class Solution {
    
    unordered_set<string>st;
    vector<string>ans;
    
    void f(int i, string& toInsert, string& path, string& s){
        if(i == s.size()){
            if(toInsert == "") ans.push_back(path); 
            return;
        }
        toInsert.push_back(s[i]);
        string aux, newPath = path + (path.size() ? " " : "") + toInsert;
        if(st.count(toInsert)) f(i + 1, aux, newPath, s);
        f(i + 1, toInsert, path, s);
        toInsert.pop_back();
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto x:wordDict) st.insert(x);
        string path, toInsert;
        f(0, toInsert, path, s);
        return ans;
    }
};

// ----------------------------------------------------------------------------------------------------------------------------

// DP

class Solution {
    
    unordered_set<string>st;
    unordered_map<int,vector<string>>dp;
    
    vector<string> f(int i, string& s){
        if(dp.count(i)) return dp[i];
        string aux;
        for(int j = i;j < s.size();j++){
            aux.push_back(s[j]);
            if(st.count(aux)){
                if(j == s.size() - 1) dp[i].push_back(aux);
                else{
                    vector<string> v = f(j + 1, s);
                    for(auto x:v){
                        dp[i].push_back(aux + " " + x);
                    }
                }
            }
        }
        return dp[i];
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto x:wordDict) st.insert(x);
        return f(0, s);
    }
};
