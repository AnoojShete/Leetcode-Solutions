class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        for(int i = 0; i < nums.size(); ++i) {
            mpp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto &[_, indices] : mpp) {
            if(indices.size() < 3) continue;
            for(int i = 0; i + 2 < indices.size(); ++i) {
                ans = min(ans, 2 * (indices[i+2] - indices[i]));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};