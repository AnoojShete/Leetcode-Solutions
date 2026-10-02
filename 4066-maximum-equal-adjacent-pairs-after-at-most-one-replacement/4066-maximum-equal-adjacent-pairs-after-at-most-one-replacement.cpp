class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, unordered_map<int, int>> mpp;
        int count = 0;
        for(int i = 1; i < n; ++i) {
            int x = nums[i-1], y = nums[i];
            if(x == y) {count++; continue;}
            mpp[x][y]++;
            mpp[y][x]++;
        }
        int ans = count;
        for(auto [_, mp] : mpp) {
            for(auto [_, f] : mp) ans = max(ans, count + f);
        }
        return ans;
    }
};