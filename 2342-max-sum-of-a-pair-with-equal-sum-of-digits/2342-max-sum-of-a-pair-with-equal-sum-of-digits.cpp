class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        int maxi = -1;
        for(auto num : nums) {
            int sum = 0;
            int temp = num;
            while(num > 0) {
                sum += num % 10;
                num = num / 10;
            }
            mpp[sum].push_back(temp);
        }
        for(auto p : mpp) {
            if(p.second.size() > 1) {
                sort(p.second.rbegin(), p.second.rend());
                maxi = max(maxi, p.second[0] + p.second[1]);
            }
        }

        return maxi;
    }
};