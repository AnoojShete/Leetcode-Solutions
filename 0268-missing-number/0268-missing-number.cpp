class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto num : nums) {
            mpp[num]++;
        }

        for(int i = 0; i <= nums.size(); ++i) {
            if(mpp[i] == 0) return i;
        }

        return -1;
    }
};