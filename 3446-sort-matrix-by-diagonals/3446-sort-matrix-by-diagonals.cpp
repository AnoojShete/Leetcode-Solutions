class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> dia;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                dia[i-j].push_back(grid[i][j]);
            }
        }
        for(auto &[x, v] : dia) {
            if(x < 0) sort(v.begin(), v.end());
            else sort(v.rbegin(), v.rend());
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                grid[i][j] = dia[i-j].front();
                dia[i-j].erase(dia[i-j].begin());
            }
        }
        return grid;
    }
};