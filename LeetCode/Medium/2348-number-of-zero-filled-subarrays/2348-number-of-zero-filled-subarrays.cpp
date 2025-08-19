class Solution {
public:
    long long zeroFilledSubarray(vector<int>& arr) {
        long long ans = 0;
        unordered_map<int, int> mpp;
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(sum == 0) ans++;
            if(mpp.find(sum) != mpp.end() && arr[i] >= 0 && sum >= 0) ans += mpp[sum];
            mpp[sum]++;
        }
        return ans;
    }
};