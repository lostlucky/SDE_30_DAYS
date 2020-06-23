class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, ans;
        while(ss >> word){
            if(ans.size()) ans = " " + ans;
            ans = word + ans;
        }
        return ans;
    }
};
