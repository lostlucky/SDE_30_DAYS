class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool>map(128, 0);
        int begin = 0, end = 0, ans = 0;
        while(end < s.size()){
            while(begin <= end and map[s[end]]) map[s[begin++]] = 0;
            map[s[end]] = 1;
            ans = max(ans, end - begin + 1);
            end++;
        }
        return ans;
    }
};
