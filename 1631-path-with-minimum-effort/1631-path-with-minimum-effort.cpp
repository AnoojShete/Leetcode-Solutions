class Solution {
public:
    bool isPossible(int row, int col, vector<vector<int>>& heights, 
    vector<vector<bool>> &vis, int n, int m, int delRow[], int delCol[], int threshold) {
        if(row == n - 1 && col == m - 1) return true;
        vis[row][col] = true;
        for(int i = 0; i < 4; ++i) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m
            && !vis[nrow][ncol]) {
                if(abs(heights[nrow][ncol] - heights[row][col]) <= threshold
                && isPossible(nrow, ncol, heights, vis, n, m, delRow, delCol, threshold)) return true;
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int left = 0;
        int right = 1e6;
        int n = heights.size();
        int m = heights[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};

        int ans = 0;
        while(left <= right) {
            vector<vector<bool>> vis(n, vector<bool>(m, false));
            int mid = (left + right) / 2;
            if(isPossible(0, 0, heights, vis, n, m, delRow, delCol, mid)) {
                right = mid - 1;
                ans = mid;
            }
            else left = mid + 1;
        }

        return ans;
    }
};