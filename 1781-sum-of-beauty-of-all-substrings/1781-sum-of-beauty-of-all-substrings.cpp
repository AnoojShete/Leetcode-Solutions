class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for(int i = 0; i < s.length(); ++i) {
            int freq[26] = {0};
            for(int j = i; j < s.length(); ++j) {
                char ch = s[j];
                freq[ch - 'a']++;
                int mini = INT_MAX;
                int maxi = INT_MIN;
                for(int k = 0; k < 26; ++k) {
                    if(freq[k] > 0) {
                        mini = min(mini, freq[k]);
                        maxi = max(maxi, freq[k]);
                    }
                }
                ans += maxi - mini;
            }
        }
        return ans;
    }
};