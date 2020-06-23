class Solution {
    
    const int mod = (int) 1e9 + 7;
    
public:
    int strStr(string s1, string s2) {
        if(!s2.size()) return 0;
        int m = s1.size(), n = s2.size();
        long reqHash = 0, rem = 1;
        for(auto x:s2) reqHash = (reqHash * 27 % mod + (x - 'a' + 1)) % mod, rem = (rem * 27) % mod;
        long hash = 0;
        
        for(int i = 0;i < m;i++){
            hash = (hash * 27 % mod + (s1[i] - 'a' + 1)) % mod;
            if(i >= n) hash -= rem * (s1[i - n] - 'a' + 1) % mod;
            if(hash < 0) hash += mod;
            if(hash == reqHash) return i - n + 1;
        }
        return -1;
    }
};
