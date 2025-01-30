class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        int n = s.length();
        int i = 0, j = 0, ans = 0;

        while(i < n && j < n) {
            if(mpp.find(s[j]) == mpp.end()) {
                mpp[s[j]]++;
                j++;
                ans = max(ans, j-i);
            }
            else {
                mpp.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};