class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()) return "";
        string prefix = strs[0];
        int index;
        for(int i = 1;i < strs.size();i++){
            for(index = 0;index < min(prefix.size(), strs[i].size());index++){
                if(strs[i][index] != prefix[index]) break;
            }
            prefix = prefix.substr(0, index);
            if(!prefix.size()) return "";
        }
        return prefix;
    }
};
