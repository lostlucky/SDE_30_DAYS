class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int16_t>row(9 ,0), col(9, 0), grid(9, 0);
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                if(board[i][j] == '.') continue;
                int16_t ch = 1 << (board[i][j] - '1');
                if( (row[i] & ch) or (col[j] & ch) or (grid[(i / 3) * 3 + (j / 3)] & ch) ) return false;
                row[i] |= ch;
                col[j] |= ch;
                grid[(i / 3) * 3 + (j / 3)] |= ch; 
            }
        }
        return true;
    }
};
