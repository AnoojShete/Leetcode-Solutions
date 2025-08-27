class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int i = 0, countZero = 0;
        int ans = 0;
        for(int j = 0; j < n; ++j) {
            countZero += !arr[j];
            while(countZero > k) {
                if(arr[i++] == 0) countZero--;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};