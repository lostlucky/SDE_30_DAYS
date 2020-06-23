class Solution {
    
    unordered_map<string, int>mp;
    
public:
    
    Solution(){
        
        mp["I"] = 1, mp["V"] = 5, mp["X"] = 10, mp["L"] = 50, mp["C"] = 100, mp["D"] = 500, mp["M"] = 1000, mp["IV"] = 4, mp["IX"] = 9, mp["IL"] = 49, mp["IC"] = 99, mp["ID"] = 499, mp["IM"] = 999, mp["XL"] = 40, mp["XC"] = 90, mp["XD"] = 490, mp["XM"] = 990, mp["CD"] = 400, mp["CM"] = 900;
        
    }

    int romanToInt(string s) {
        
         
        
        s.push_back('#');
        
        int ans = 0;
        
        for(int i = 0;i < s.size() - 1;i++){
            if(mp.count(s.substr(i, 2))) ans += mp[s.substr(i++, 2)];
            else ans += mp[s.substr(i, 1)];
        }
        
        return ans;
    }
};
