// 🤧😷

typedef long long ll;

class Solution {
public:
    bool isValid(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_map<ll, int> left, right;
        ll leftSum = 0, total = 0, rightSum;
        for(auto row : grid) for(auto cell : row) right[cell]++, total += cell;
        rightSum = total;
        for(int c = 0; c < n-1; ++c) {
            for(int r = 0; r < m; ++r) {
                int val = grid[r][c];
                left[val]++;
                if(--right[val] == 0) right.erase(val);
                leftSum += val, rightSum -= val;
            }
            if(leftSum == rightSum) return true;
            ll diff = abs(leftSum - rightSum);

            int leftRows = m, leftCols = c+1;
            int rightRows = m, rightCols = n-c-1;

            bool left2D = leftRows > 1 && leftCols > 1;
            bool right2D = rightRows > 1 && rightCols > 1;
            
            if(leftSum > rightSum) {
                if(left2D) {
                    if(left.count(diff)) return true;
                } else {
                    if(leftRows == 1) {
                        if(grid[0][0] == diff || grid[0][c] == diff)
                            return true;
                    } 
                    else if(leftCols == 1) {
                        if(grid[0][0] == diff || grid[m-1][0] == diff)
                            return true;
                    }
                }
            }
            else {
                if(right2D) {
                    if(right.count(diff)) return true;
                } else {
                    if(rightRows == 1) {
                        if(grid[0][c+1] == diff || grid[0][n-1] == diff)
                            return true;
                    } 
                    else if(rightCols == 1) {
                        if(grid[0][c+1] == diff || grid[m-1][c+1] == diff)
                            return true;
                    }
                }
            }
        }
        return false;
    }
    vector<vector<int>> rotate(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> rGrid(n, vector<int>(m));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                rGrid[j][m-i-1] = grid[i][j];
            }
        }
        return rGrid;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m == 1 && n == 1) return false;
        if(isValid(grid)) return true;
        vector<vector<int>> rGrid = rotate(grid);
        if(isValid(rGrid)) return true;
        return false;
    }
};