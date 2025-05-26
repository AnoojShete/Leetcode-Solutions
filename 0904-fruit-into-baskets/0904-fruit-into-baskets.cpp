class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size() < 2) return fruits.size();
        int i = 0, j = 0;
        unordered_map<int, int> mpp;
        int ans = 0;
        while(j < fruits.size()) {
            mpp[fruits[j]]++;
            while(mpp.size() > 2) {
                mpp[fruits[i]]--;
                if(mpp[fruits[i]] == 0) mpp.erase(fruits[i]);
                i++;
            }
            if(mpp.size() == 2) {
                ans = max(ans, j - i + 1);
            }
            j++;
        }
        return ans;
    }
};