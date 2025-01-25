class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        unordered_map<int, int> mpp;
        int res = 0;
        int preSum = 0;
        for(int i = 0; i < arr.size(); i++) {
            preSum += arr[i] == 0 ? -1 : 1;
            if(preSum == 0) {
                res = i + 1;
            }
            if(mpp.find(preSum) != mpp.end()) {
                res = max(res, i - mpp[preSum]);
            }
            else
                mpp[preSum] = i;
        }
        
        return res;
    }
};