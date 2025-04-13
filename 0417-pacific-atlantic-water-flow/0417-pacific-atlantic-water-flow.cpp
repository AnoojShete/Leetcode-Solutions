class Solution {
public:
    bool inBounds(int row, int col, int n, int m) {
        return row >= 0 && row < n && col >= 0 && col < m;
    }
    void dfs(int row, int col, vector<vector<int>> &adj, int n, int m,
    vector<vector<bool>> &vis, int prevHeight) {
        vis[row][col] = true;
        int delta[] = {-1, 0, 1, 0, -1};
        for(int i = 0; i < 4; ++i) {
            int nrow = row + delta[i];
            int ncol = col + delta[i + 1];
            if(inBounds(nrow, ncol, n, m) && 
            !vis[nrow][ncol] && adj[nrow][ncol] >= prevHeight) {
                dfs(nrow, ncol, adj, n, m, vis, adj[nrow][ncol]);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));
        for(int i = 0; i < n; ++i) {
            dfs(i, 0, heights, n, m, pac, heights[i][0]); // left edge
            dfs(i, m - 1, heights, n, m, atl, heights[i][m - 1]); // right edge
        }
        for(int i = 0; i < m; ++i) {
            dfs(0, i, heights, n, m, pac, heights[0][i]); // top
            dfs(n - 1, i, heights, n, m, atl, heights[n - 1][i]); // bottom
        }

        vector<vector<int>> ans;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(pac[i][j] && atl[i][j]) {
                    // cout << "pac and atl meet at: " << i << " " << j << endl;
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};