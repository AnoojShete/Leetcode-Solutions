class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int d = -1;
        for(int i = 1; i < arr.size(); ++i) {
            if(d != -1 && arr[i] - arr[i-1] != d) return false;
            d = arr[i] - arr[i-1];
        }
        return true;
    }
};