class Solution {
public:
    bool isPossible(vector<int> &ranks, int cars, int mid) {
        int count = 0;
        for(int i = 0; i < ranks.size(); ++i) {
            count += floor(sqrt(mid / ranks[i]));
        }
        return count >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int low = 0;
        int mx = *max_element(ranks.begin(), ranks.end());
        int high = mx * cars * cars;
        while(low < high) {
            int mid = (low + high) / 2;
            if(isPossible(ranks, cars, mid)) {
                high = mid;
            }
            else low = mid + 1;
        }

        return low;
    }
};