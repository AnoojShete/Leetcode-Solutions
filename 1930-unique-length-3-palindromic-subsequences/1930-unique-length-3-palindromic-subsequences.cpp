class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<int> first(26, n), last(26, -1);
        for(int i = 0; i < n; ++i) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = max(last[s[i] - 'a'], i);
        }
        int ans = 0;
        for(int ch = 0; ch < 26; ++ch) {
            if(first[ch] == n) continue;
            if(first[ch] == last[ch]) continue;
            vector<bool> seen(26, false);
            int count = 0;
            for(int i = first[ch] + 1; i < last[ch]; ++i) {
                if(!seen[s[i] - 'a']) count++;
                seen[s[i] - 'a'] = true;
            }
            ans += count;
        }
        return ans;
    }
};