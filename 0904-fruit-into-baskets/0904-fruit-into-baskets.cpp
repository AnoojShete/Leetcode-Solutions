class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mpp;
        int l = 0;
        int ans = 0;
        for(int r = 0; r < fruits.size(); ++r) {
            mpp[fruits[r]]++;
            while(mpp.size() > 2) {
                if(mpp[fruits[l]] == 1) {
                    mpp.erase(fruits[l]);
                }
                else mpp[fruits[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};