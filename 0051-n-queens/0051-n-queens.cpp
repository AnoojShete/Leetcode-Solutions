class Solution {
public:
    bool isValid(int row, int col, vector<string> &board) {
        int duprow = row, dupcol = col;
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--, col--;
        }
        row = duprow, col = dupcol;
        while(col >= 0) {
            if(board[row][col] == 'Q') return false;
            col--;
        }
        row = duprow, col = dupcol;
        while(row < board.size() && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row++, col--;
        }
        return true;
    }
    void solve(int n, int colIndex, vector<string> &board, vector<vector<string>> &ans) {
        if(colIndex == n) {
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++) {
            if(isValid(row, colIndex, board)) {
                board[row][colIndex] = 'Q';
                solve(n, colIndex + 1, board, ans);
                board[row][colIndex] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> ans;
        string s(n, '.');
        for(int i = 0; i < n; ++i) {
            board[i] = s;
        }
        solve(n, 0, board, ans);

        return ans;
    }
};