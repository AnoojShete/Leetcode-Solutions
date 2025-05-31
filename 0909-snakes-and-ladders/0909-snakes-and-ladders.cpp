class Solution {
public:
    pair<int, int> cellToPos(int cell, int n) {
        int row = n - 1 - (cell - 1) / n;
        int colBase = (cell - 1) % n;

        int col;
        if ((n - 1 - row) % 2 == 0) {
            col = colBase; // left to right
        } else {
            col = n - 1 - colBase; // right to left
        }

        return {row, col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> vis(n * n + 1, false);
        queue<int> q;
        q.push(1);
        vis[1] = true;
        int moves = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int cell = q.front(); q.pop();
                for(int dice = 1; dice <= 6; ++dice) {
                    int nextCell = cell + dice;
                    if(nextCell > n * n) continue;
                    auto [row, col] = cellToPos(nextCell, n);
                    if(board[row][col] != -1) {
                        nextCell = board[row][col];
                    }
                    if(nextCell == n * n) return moves + 1;
                    if(!vis[nextCell]) {
                        vis[nextCell] = true;
                        q.push(nextCell);
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};