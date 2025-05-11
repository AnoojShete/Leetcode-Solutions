class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size() < 3) return false;
        for(int i = 0; i < arr.size() - 3; ++i) {
            int count = 0;
            for(int j = i; j < i + 3; ++j) {
                if(arr[j] % 2 != 0) count++;
                if(count == 3) return true;
            }
        }

        return false;
    }
};