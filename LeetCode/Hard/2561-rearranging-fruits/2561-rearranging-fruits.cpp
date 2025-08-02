typedef long long ll;

class Solution {
public:
    ll minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mpp1, mpp2, totalCount;
        int miniCost = INT_MAX;
        for(auto it : basket1) {
            mpp1[it]++;
            totalCount[it]++;
            miniCost = min(miniCost, it);
        }
        for(auto it : basket2) {
            mpp2[it]++;
            totalCount[it]++;
            miniCost = min(miniCost, it);
        }
        vector<int> v;
        for(auto &[val, freq] : totalCount) {
            if(freq & 1) return -1;
        }
        for(auto &[val, freq] : mpp1) {
            int diff = freq - totalCount[val]/2;
            for(int i = 0; i < diff; ++i) {
                v.push_back(val);
            }
        }
        for(auto &[val, freq] : mpp2) {
            int diff = freq - totalCount[val]/2;
            for(int i = 0; i < diff; ++i) {
                v.push_back(val);
            }
        }
        sort(v.begin(), v.end());
        ll ans = 0; 
        for(int i = 0; i < v.size()/2; ++i) {
            ans += min(1LL*v[i], 2LL*miniCost);
        }
        return ans;
    }
};