class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int low = 0, high = arr.size()-1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(arr[mid] < x) low = mid + 1;
            else high = mid - 1;
        }
        int left = high, right = high + 1;
        while(left >= 0 && right < arr.size() && ans.size() < k) {
            if(abs(arr[right] - x) < abs(arr[left] - x)) {
                ans.push_back(arr[right]);
                right++;
            }
            else {
                ans.push_back(arr[left]);
                left--;
            }
        }
        while(right < arr.size() && ans.size() < k) {
            ans.push_back(arr[right]);
            right++;
        }
        while(left >= 0 && ans.size() < k) {
            ans.push_back(arr[left]);
            left--;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};