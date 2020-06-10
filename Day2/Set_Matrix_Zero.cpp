class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool rowZero = 0, colZero = 0;
        
        if(!matrix.size()) return;        
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i = 0;i < m;i++){
            if(matrix[i][0] == 0) colZero = 1;
            if(colZero) break;
        }
        
        for(int j = 0;j < n;j++){
            if(matrix[0][j] == 0) rowZero = 1;
            if(rowZero) break;
        }
        
        for(int i = 1;i < m;i++){
            for(int j = 1;j < n;j++){
                if(matrix[i][j] == 0) matrix[0][j] = matrix[i][0] = 0;
            }
        }
        
        for(int i = 1;i < m;i++){
            if(matrix[i][0] == 0) {
                for(int j = 1;j < n;j++){
                    matrix[i][j] = 0;
                }
            }
        }
        
        for(int j = 1;j < n;j++){
            if(matrix[0][j] == 0){
                for(int i = 1;i < m;i++){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(colZero) for(int i = 0;i < m;i++) matrix[i][0] = 0;
        if(rowZero) for(int j = 0;j < n;j++) matrix[0][j] = 0;
        
    }
};
