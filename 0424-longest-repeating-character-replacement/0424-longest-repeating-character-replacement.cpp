class Solution {
public:
    int characterReplacement(string s, int k) {
        int mpp[26] = {0};
        int i = 0, ans = 0, maxi = 0;
        for(int j = 0; j < s.length(); ++j) {
            mpp[s[j] - 'A']++;
            maxi = max(maxi, mpp[s[j]- 'A']);
            while(j - i + 1 - maxi > k) {
                mpp[s[i++] - 'A']--;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};