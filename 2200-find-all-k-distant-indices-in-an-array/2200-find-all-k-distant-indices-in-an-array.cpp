class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ans;
        int idx = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == key) {
                int left = max(0, i-k);
                int right = min(i+k, n-1);
                while(idx <= right) {
                    if(idx >= left) ans.push_back(idx);
                    idx++;
                }
            }
        }
        return ans;
    }
};