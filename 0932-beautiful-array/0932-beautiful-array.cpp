class Solution {
public:
    vector<int> beautifulArray(int n) {
        if(n == 1) return {1};
        vector<int> ans;
        auto odd = beautifulArray((n + 1) / 2);
        for(auto num : odd) ans.push_back(2 * num - 1);
        auto even = beautifulArray(n / 2);
        for(auto num : even) ans.push_back(2 * num);

        return ans;
    }
};