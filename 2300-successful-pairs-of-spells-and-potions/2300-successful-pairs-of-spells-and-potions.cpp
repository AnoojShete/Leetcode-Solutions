typedef long long ll;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        sort(potions.begin(), potions.end());
        vector<int> ans(n);
        for(int i = 0; i < n; ++i) {
            int left = 0, right = potions.size()-1;
            while(left <= right) {
                int mid = (left + right) / 2;
                ll prod = 1LL * spells[i] * potions[mid];
                if(prod >= success) right = mid - 1;
                else left = mid + 1;
            }
            ans[i] = potions.size() - left;
        }
        return ans;
    }
};