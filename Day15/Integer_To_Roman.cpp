class Solution {
public:
    string intToRoman(int num) {
        vector<int>values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string>str = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string ans;
        int mul;
        
        for(int i = 0;i < values.size();i++){
            if(num >= values[i]){
                mul = num / values[i];
                num -= mul * values[i];
                while(mul--) ans += str[i];
            }
            if(!num) break;
        }
        
        return ans;
    }
};
