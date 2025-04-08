class Solution {
public:
    bool isDistinctArray(vector<int> &nums, int mpp[]) {
        for(auto num : nums) if(mpp[num] > 1) return false;
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        int mpp[101] = {0};
        bool isDistinct = true;
        for(auto num : nums) {
            mpp[num]++;
            if(mpp[num] > 1) isDistinct = false;
        }
        if(isDistinct) return 0;

        int operations = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(!isDistinctArray(nums, mpp)) {
                if(nums.size() < 3) return operations + 1;
                for(int k = 0; k < nums.size(); ++k) {
                    nums.erase(nums.begin());
                }
                operations++;
            }
        }

        return operations;
    }
};