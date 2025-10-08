typedef long long ll;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        vector<pair<int, int>> indexedSpells(n);
        for(int i = 0; i < n; ++i) {
            indexedSpells[i] = {spells[i], i};
        }
        sort(indexedSpells.rbegin(), indexedSpells.rend());
        sort(potions.begin(), potions.end());
        vector<int> ans(n);
        int i = 0;
        for(auto &[spell, idx] : indexedSpells) {
            while(i < potions.size() && 1LL * spell * potions[i] < success) {
                ++i;
            }
            ans[idx] = potions.size() - i;
        }
        return ans;
    }
};