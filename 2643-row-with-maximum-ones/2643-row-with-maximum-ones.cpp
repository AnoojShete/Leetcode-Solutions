class Solution {
public:
    int lower_bound(vector<int> &arr) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(arr[mid]) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxi = 0;
        int ans1 = -1;
        int ans2 = 0;
        for(int i = 0; i < n; i++) {
            sort(mat[i].begin(), mat[i].end());
            int index = lower_bound(mat[i]);
            if(m - index > maxi) {
                ans1 = i;
                ans2 = m - index;
                maxi = m - index;
            }
        }

        return {ans1, ans2};
    }
};