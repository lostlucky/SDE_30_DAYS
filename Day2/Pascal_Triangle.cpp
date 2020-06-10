class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>pascalTriangle(numRows);
        if(numRows == 0) return pascalTriangle;
        pascalTriangle[0] = {1};
        if(numRows == 1) return pascalTriangle;
        pascalTriangle[1] = {1,1};
        if(numRows == 2) return pascalTriangle;
        for(int i = 2;i < numRows;i++){
            pascalTriangle[i].push_back(1);
            for(int j = 0;j < pascalTriangle[i - 1].size() - 1;j++){
                pascalTriangle[i].push_back(pascalTriangle[i - 1][j] + pascalTriangle[i - 1][j + 1]);
            }
            pascalTriangle[i].push_back(1);
        }
        return pascalTriangle;
    }
};
