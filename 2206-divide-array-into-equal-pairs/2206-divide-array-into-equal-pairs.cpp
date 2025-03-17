class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int hashMpp[501] = {0};
        for(auto &num : nums) {
            hashMpp[num]++;
        }
        for(auto it : hashMpp) {
            if(it % 2 != 0) return false;
        }
        return true;
    }
};