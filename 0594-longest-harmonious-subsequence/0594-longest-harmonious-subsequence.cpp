class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int ans = 0;
        for(auto it : nums) mpp[it]++;

        for(auto p : mpp) {
            int num = p.first;
            if(mpp.find(num + 1) != mpp.end()) {
                ans = max(ans, mpp[num] + mpp[num + 1]);
            }
        }

        return ans;
    }
};