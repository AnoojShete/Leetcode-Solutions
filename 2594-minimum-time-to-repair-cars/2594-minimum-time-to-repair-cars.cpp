class Solution {
public:
    bool isPossible(vector<int> &ranks, int cars, long long mid) {
        long long count = 0;
        for(int i = 0; i < ranks.size(); ++i) {
            count += (long long)(sqrt(mid / ranks[i]));
        }
        return count >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 0;
        int mx = *max_element(ranks.begin(), ranks.end());
        long long high = 1e14;

        long long ans = 0;
        while(low <= high) {
            long long mid = (low + high) / 2;
            if(isPossible(ranks, cars, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return low;
    }
};