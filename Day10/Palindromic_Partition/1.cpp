class Solution {
    
    vector<vector<int>>palin;
    vector<vector<string>>ans;
    
    void calPalin(int left, int right, string& s){
        while(left >= 0 and right < s.size() and s[left] == s[right]){
            palin[left].push_back(right + 1);
            left--, right++;
        }
    }
    
    void f(int i, vector<string>& sub, string& s){
        if(i == s.size()){
            ans.push_back(sub);
            return;
        }
        for(auto nextIndex:palin[i]){
            sub.push_back(s.substr(i, nextIndex - i));
            f(nextIndex,sub,s);
            sub.pop_back();
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        
        palin.resize(s.size());
        
        for(int i = 0;i < s.size();i++){
            calPalin(i,i,s);
            calPalin(i,i + 1,s);
        }
        vector<string>sub;
        
        f(0,sub,s);
        
        return ans;
    }
};
