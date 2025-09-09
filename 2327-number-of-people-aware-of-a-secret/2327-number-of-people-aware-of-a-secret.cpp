class Solution {
public:
    const int MOD = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        queue<tuple<int, int, int>> q;
        q.push({forget + 1, delay + 1, 1});
        for(int day = 2; day <= n; ++day) {
            while(!q.empty() && get<0>(q.front()) <= day) q.pop();
            int count = 0;
            int sz = q.size();
            for(int k = 0; k < sz; k++) {
                auto [forgor, reveal, cnt] = q.front();
                q.pop();
                if(reveal <= day) count = (count + cnt) % MOD;
                q.push({forgor, reveal, cnt}); 
            }
            if(count > 0) q.push({day + forget, day + delay, count});
        }
        int ans = 0;
        while(!q.empty()) {
            ans += get<2>(q.front()); q.pop();
        }
        return ans;
    }
};