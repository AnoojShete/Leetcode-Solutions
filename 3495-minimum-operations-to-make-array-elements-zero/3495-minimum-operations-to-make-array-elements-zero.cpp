typedef long long ll;

class Solution {
public:
    ll minOperations(vector<vector<int>>& queries) {
        ll ans = 0;
        for(auto &q : queries) {
            int l = q[0], r = q[1];
            ans += r-l;
        }
        return ans;
    }
};