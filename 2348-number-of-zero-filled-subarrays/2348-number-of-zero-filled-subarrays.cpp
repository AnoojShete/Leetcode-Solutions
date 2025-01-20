class Solution {
public:
    long long zeroFilledSubarray(vector<int>& arr) {
        long long res = 0;
        int n = arr.size();
        for(int i = 0, j = 0; i < n; i++) {
            if(arr[i] != 0) {
                j = i + 1;
            }
            res += i - j + 1;
        }
        return res;
    }
};