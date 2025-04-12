class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;
        int freq[1001] = {0};
        for(auto &v : nums) {
            for(auto it : v) {
                freq[it]++;
                if(freq[it] == nums.size()) ans.push_back(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};