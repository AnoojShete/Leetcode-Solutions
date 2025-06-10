class Solution {
public:
    int maxDifference(string s) {
        int mpp[26] = {0};
        int even = INT_MAX, odd = 0;
        for(auto ch : s) mpp[ch-'a']++;
        for(int i = 0; i < 26; ++i) {
            if(mpp[i] != 0) {
                if(mpp[i] % 2 == 0) even = min(even, mpp[i]);
                else odd = max(odd, mpp[i]);
            }
        }
        return odd - even;
    }
};