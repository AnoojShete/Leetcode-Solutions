typedef long long ll;

class Solution {
public:
    bool isValid(int n, vector<int> &batteries, ll mid) {
        ll time = 0;
        for(auto batt : batteries) {
            time += min(1LL*batt, mid);
        }
        return time / n >= mid;
    }
    ll maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());
        ll low = 0, high = accumulate(batteries.begin(), batteries.end(), 0LL);
        while(low <= high) {
            ll mid = (low + high) / 2;
            if(isValid(n, batteries, mid)) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};