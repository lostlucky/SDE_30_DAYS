// Sudoku Solver

class Solution {

  bool backtrack(int i, int j, vector < vector < char >>& board, vector < int16_t >& row, vector < int16_t >& col, vector < int16_t >& grid) {
      
      if(i == 9) return 1;
      
      if(j == 9) return backtrack(i + 1, 0, board, row, col, grid);
      
      if (board[i][j] != '.') return backtrack(i, j + 1, board, row, col, grid);
      
      for (int ch = 1; ch <= 9; ch++) {
        
          int16_t shift = 1 << ch;
          if ( (row[i] & shift) or (col[j] & shift) or (grid[(i / 3) * 3 + j / 3] & shift) ) continue;
          
          board[i][j] = ch + '0';
          row[i] |= shift, col[j] |= shift, grid[(i / 3) * 3 + j / 3] |= shift;
          
          bool ans = backtrack(i, j + 1, board, row, col, grid);
          
          if(ans) return 1;
          
          row[i] ^= shift, col[j] ^= shift, grid[(i / 3) * 3 + j / 3] ^= shift;
          
      }
      board[i][j] = '.';
      
      return 0;
  }

  public:
    void solveSudoku(vector < vector < char >> & board) {
        
        vector < int16_t > row(9, 0), col(9, 0), grid(9, 0);
        
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                if(board[i][j] == '.')  continue;
                int shift = 1 << (board[i][j] - '0');
                row[i] |= shift, col[j] |= shift, grid[(i / 3) * 3 + j / 3] |= shift;
            }
        }
        
        backtrack(0, 0, board, row, col, grid);
    }
};
