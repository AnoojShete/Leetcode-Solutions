class Solution {
public:
    bool isValid(vector<vector<int>> &board) {
        vector<vector<int>> correct = {{1, 2, 3}, {4, 5, 0}};
        return board == correct;
    }
    bool inBounds(int row, int col, int n, int m) {
        return row >= 0 && col >= 0 && row < n && col < m;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        int n = 2, m = 3;
        
        set<vector<vector<int>>> vis;
        queue<vector<vector<int>>> q;
        q.push(board);
        vis.insert(board);

        int moves = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto node = q.front();
                q.pop();
                if(isValid(node)) return moves;

                int row = -1, col = -1;
                for(int i = 0; i < node.size(); ++i) {
                    for(int j = 0; j < node[0].size(); ++j) {
                        if(node[i][j] == 0) {
                            row = i, col = j;
                        }
                    }
                }
                int delta[] = {-1, 0, 1, 0, -1};
                for(int i = 0; i < 4; ++i) {
                    int nrow = row + delta[i];
                    int ncol = col + delta[i + 1];
                    if(inBounds(nrow, ncol, n, m)) {
                        auto temp = node;
                        swap(temp[row][col], temp[nrow][ncol]);
                        if(vis.find(temp) == vis.end()) {
                            q.push(temp);
                            vis.insert(temp);
                        }
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};