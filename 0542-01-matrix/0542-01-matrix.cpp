class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        while(!q.empty()) {
            auto p = q.front(); q.pop();
            int r = p.first.first, c = p.first.second;
            int dist = p.second;
            ans[r][c] = dist;
            for(int i = 0; i < 4; i++) {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n &&
                ncol < m && !visited[nrow][ncol]) {
                    q.push({{nrow, ncol}, dist + 1});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        return ans;
    }
};