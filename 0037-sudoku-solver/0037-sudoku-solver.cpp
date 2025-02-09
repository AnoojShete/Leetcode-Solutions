class Solution {
public:
    bool isValid(int row, int col, int num, vector<vector<char>> &board) {
        // check row
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == num) return false;
        }
        // check column
        for(int i = 0; i < 9; i++) {
            if(board[row][col] == num) return false;
        }
        // Check in subgrid
        int start_row = row - row % 3;
        int start_col = col - col % 3;
        for(int i = start_row; i < start_row + 3; i++) {
            for(int j = start_col; j < start_col + 3; j++) {
                if(board[i][j] == num)
                    return false;
            }
        }

        return true;
    }
    void solve(int row, int col, vector<vector<char>> &board) {
        if(row > 9 && col > 9) {
            return;
        }
        if(col > 9) {
            solve(row + 1, 0, board);
        }

        for(int i = 1; i <= 9; i++) {
            if(isValid(row, col, i, board)) {
                board[row][col] = '0' + i;
                solve(row, col + 1, board);
                // backtrack
                board[row][col] = '.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(0, 0, board);
    }
};