class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int x) {
        int n = arr.size();
        int m = arr[0].size();
        int row = 0, col = m - 1;
        while(row < m && col >= 0) {
            if(arr[row][col] == x) return true;
            else if(arr[row][col] > x) col--;
            else row++;
        }

        return false;
    }
};