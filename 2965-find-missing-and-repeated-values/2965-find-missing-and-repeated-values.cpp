class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int mpp[2501] = {0};
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                mpp[grid[i][j]]++;
            }
        }
        int missing = -1, repeated = -1;
        for(int i = 1; i < 2501; ++i) {
            if(missing == -1) {
                if(mpp[i] == 0) missing = i;
            }
            if(mpp[i] > 1) repeated = i;
        }
        return {repeated, missing};
    }
};