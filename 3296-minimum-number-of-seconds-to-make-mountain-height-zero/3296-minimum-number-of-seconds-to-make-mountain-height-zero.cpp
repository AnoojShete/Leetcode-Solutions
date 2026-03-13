typedef long long ll;

class Solution {
public:
    ll calcWorkTime(int workTime, ll x) {
        return 1LL * workTime * (x * (x + 1)) / 2;
    }
    bool isPossible(int mountainHeight, vector<int> &workerTimes, ll mid) {
        int reducedHeight = 0;
        for(auto &t : workerTimes) {
            int x = floor((-1 + sqrt(1 + 8 * mid / t)) / 2);
            reducedHeight += x;
        }
        return reducedHeight >= mountainHeight;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll low = 0, high = calcWorkTime(*max_element(workerTimes.begin(), workerTimes.end()), mountainHeight);
        while(low <= high) {
            const ll mid = low + (high - low) / 2;
            if(isPossible(mountainHeight, workerTimes, mid)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};