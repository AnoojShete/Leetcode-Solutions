typedef long long ll;
typedef vector<int> vi;

class Solution {
public:
    bool solve(vi &candies, ll k, int mid) {
        ll count = 0;
        for(int i = 0; i < candies.size(); ++i) {
            count += candies[i] / mid;
            if(count >= k) return true;
        }
        return count >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        ll sum = accumulate(candies.begin(), candies.end(), 0);
        if(sum < k) return 0;

        int low = 1;
        int high = *max_element(candies.begin(), candies.end());

        int ans = 0;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(solve(candies, k, mid)) {
                low = mid + 1;
                ans = max(ans, mid);
            }
            else high = mid - 1;
        }

        return ans;
    }
};