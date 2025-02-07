class Solution {
public:
    bool solve(int r, int c, int i,
        vector<vector<char>> &board, string &word) {
        if(i == word.size()) return true;
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() ||
            board[r][c] != word[i] || board[r][c] == '#') {
            return false;
        }
        char temp = board[r][c];
        board[r][c] = '#';
        bool ans = (solve(r+1, c, i + 1, board, word) ||
                    solve(r, c+1, i + 1, board, word) ||
                    solve(r-1, c, i + 1, board, word) ||
                    solve(r, c-1, i + 1, board, word));

        board[r][c] = temp;

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size(), c = board[0].size();
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(board[i][j] == word[0] && solve(i, j, 0, board, word))
                    return true;
            }
        }

        return false;
    }
};