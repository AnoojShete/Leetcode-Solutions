class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> sortedNums;
        for(int i = 0; i < n; ++i) {
            sortedNums.push_back({nums[i], i});
        }
        auto sum = [](int a) {
            int s = 0;
            while(a) {
                s += a % 10;
                a /= 10;
            }
            return s;
        };
        sort(sortedNums.begin(), sortedNums.end(), [&](auto a, auto b) {
            int aSum = sum(a.first), bSum = sum(b.first);
            if(aSum != bSum) return aSum < bSum;
            return a.first < b.first;
        });
        int ans = 0;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; ++i) {
            if(vis[i]) continue;
            int j = i;
            int cycles = 0;
            while(!vis[j]) {
                vis[j] = true;
                cycles++;
                j = sortedNums[j].second;
            }
            ans += cycles - 1;
        }
        return ans;
    }
};