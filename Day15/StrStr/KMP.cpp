class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if(n == 0) return 0;
        vector<int>lps(n, 0);
        int i = 1, j = 0;
        while(i < n){
            if(needle[i] == needle[j]) lps[i++] = ++j;
            else if(j) j = lps[j - 1];
            else i++;
        }
        i = 0, j = 0;
        while(i < m){
            if(haystack[i] == needle[j]) i++, j++;
            else if(j) j = lps[j - 1];
            else i++;
            if(j == n) return i - n;
        }
        return -1;
    }
};
