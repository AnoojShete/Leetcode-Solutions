class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &image, vector<vector<int>> &ans,
            int delRow[], int delCol[], int init_color, int color) {
            int n = image.size();
            int m = image[0].size();
            ans[row][col] = color;
            for(int i = 0; i < 4; ++i) {
                for(int j = 0; j < 4; ++j) {
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];
                    if(nrow >= 0 && ncol >= 0 && nrow < n &&
                    ncol < m && image[nrow][ncol] == init_color &&
                    ans[nrow][ncol] != color) {
                        dfs(nrow, ncol, image, ans, delRow, delCol, init_color, color);
                    }
                }
            }
        }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int init_color = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        dfs(sr, sc, image, ans, delRow, delCol, init_color, color);

        return ans;
    }
};