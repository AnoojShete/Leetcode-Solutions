class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> boxes[9];
        
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') continue;
                char value = board[i][j];
                int boxIndex = (i / 3) * 3 + (j / 3);

                if(row[i].count(value) || col[j].count(value) || boxes[boxIndex].count(value)) return false;

                row[i].insert(value);
                col[j].insert(value);
                boxes[boxIndex].insert(value);
            }
        }

        return true;
    }
};