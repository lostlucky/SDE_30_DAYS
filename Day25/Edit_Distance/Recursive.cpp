class Solution {
public:
    vector<vector<int>>dp;
    string word1,word2;
    const int INF = 1e9;
    int minDistance(string word1, string word2) {
        dp.resize(word1.size(),vector<int>(word2.size(),-1));
        this -> word1 = word1,this -> word2 = word2;
        return f(0,0);
    }
    
    int f(int i,int j){
        if(i > word1.size() or j > word2.size()) return INF;
        if(j == word2.size()) return (word1.size() - i);
        if(i == word1.size()) return (word2.size() - j);
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) return dp[i][j] = f(i + 1,j + 1);
        return dp[i][j] = min({!(word1[i] == word2[j]) + f(i + 1,j + 1),1 + f(i + 1,j),1 + f(i,j + 1)});
    }
};
