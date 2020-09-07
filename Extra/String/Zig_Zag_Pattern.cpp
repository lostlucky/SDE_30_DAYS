class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>eachRow(numRows);
        if(numRows == 1) return s;
        for(int i = 0, row = 0, step;i < s.size();i++){
            eachRow[row].push_back(s[i]);
            if(row == 0) step = 1;
            else if(row == numRows - 1) step = -1;
            row += step;
        }
        string ans;
        for(auto str:eachRow) ans += str;
        return ans;
    }
};
