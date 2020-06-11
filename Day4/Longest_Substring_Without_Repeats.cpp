class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, ans = 0;
        unordered_map<char,int>mp;
        for(int end = 0;end < s.size();end++){
            if(mp.count(s[end])){
                start = max(start, mp[s[end]] + 1);
            }
            ans = max(ans, end - start + 1);
            mp[s[end]] = end;
        }
        return ans;
    }
};
