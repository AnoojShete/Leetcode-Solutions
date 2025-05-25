class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> mpp;
        int ans = 0;
        int i = 0, j = 0;
        while(j < n) {
            mpp[s[j]]++;
            while(mpp[s[j]] > 1) {
                mpp[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            ++j;
        }

        return ans;
    }
};