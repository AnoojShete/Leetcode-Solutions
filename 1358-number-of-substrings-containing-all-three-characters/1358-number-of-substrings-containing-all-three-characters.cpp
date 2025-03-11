class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int ans = 0;
        unordered_map<char, int> mpp = {{'a', 0}, {'b', 0}, {'c', 0}};

        for(int r = 0; r < s.size(); ++r) {
            mpp[s[r]]++;
            while(mpp['a'] > 0 && mpp['b'] > 0 && mpp['c'] > 0) {
                ans += s.size() - r;
                mpp[s[l]]--;
                l++;
            }
        }

        return ans;
    }
};