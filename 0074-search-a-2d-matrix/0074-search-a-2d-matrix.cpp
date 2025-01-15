class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int x) {
        int n = arr.size(), m = arr[0].size();
        int low = 0, high = n*m - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            int row = mid / m, col  = mid % m;
            if(arr[row][col] == x) return true;
            if(arr[row][col] < x) low = mid + 1;
            else high = mid - 1;
        }

        return false;
    }
};