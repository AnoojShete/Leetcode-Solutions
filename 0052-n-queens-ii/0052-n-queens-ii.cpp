class Solution {
public:
    bool isValid(int rowIndex, int colIndex, vector<vector<int>> &board) {
        int duprow = rowIndex;
        int dupcol = colIndex;
        while(rowIndex >= 0 && colIndex >= 0) {
            if(board[rowIndex][colIndex]) return false;
            rowIndex--;
            colIndex--;
        }
        rowIndex = duprow;
        colIndex = dupcol;
        while(colIndex >= 0) {
            if(board[rowIndex][colIndex]) return false;
            colIndex--;
        }
        rowIndex = duprow;
        colIndex = dupcol;
        while(rowIndex < board.size() && colIndex >= 0) {
            if(board[rowIndex][colIndex]) return false;
            rowIndex++, colIndex--;
        }
        return true;
    }
    
    void solve(int colIndex, int n, vector<vector<int>> &board, int &ans) {
        if(colIndex == n) {
            ans++;
            return;
        }
        for(int row = 0; row < n; row++) {
            if(isValid(row, colIndex, board)) {
                board[row][colIndex] = 1;
                solve(colIndex + 1, n, board, ans);
                board[row][colIndex] = 0;
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n ,0));
        int ans = 0;
        solve(0, n, board, ans);
        
        return ans;
    }
};