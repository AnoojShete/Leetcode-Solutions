typedef long long ll;

class Solution {
public:
    int maximumCandies(vector<int>& candies, ll k) {
        int low = 0;
        int high = 1e7;

        while(low < high) {
            int mid = (low + high + 1) / 2;
            long count = 0;
            for(int i = 0; i < candies.size() && count < k; ++i) {
                count += candies[i] / mid;
            }
            if(count >= k) low = mid;
            else high = mid - 1;
        }

        return low;
    }
};