class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        int i = 0, ans = 0;
        for(int j = 0; j < s.length(); ++j) {
            mpp[s[j]]++;
            while(mpp[s[j]] > 1) {
                mpp[s[i++]]--;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};