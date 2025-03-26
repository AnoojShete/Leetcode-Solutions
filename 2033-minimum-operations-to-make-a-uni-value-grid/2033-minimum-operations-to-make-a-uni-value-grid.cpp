class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> sorted_grid;
        for(auto &v : grid) {
            for(auto ele : v) {
                sorted_grid.push_back(ele);
            }
        }
        sort(sorted_grid.begin(), sorted_grid.end());
        int mid_element = sorted_grid[n * m / 2];

        int MOD = sorted_grid[0] % x;
        int count = 0;
        for(auto &ele : sorted_grid) {
            if(ele % x != MOD) return -1;
            if(ele == mid_element) continue;
            count += abs(ele - mid_element) / x;
        }

        return count;
    }
};