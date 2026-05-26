class Solution {
public:
    int numberOfSpecialChars(string word) {
        int mpp[52] = {0};
        for(auto ch : word) {
            if(islower(ch)) mpp[ch-'a']++;
            else mpp[ch-'A' + 26]++;
        }
        int count = 0;
        for(int i = 0; i < 26; ++i) if(mpp[i] && mpp[i+26]) count++;
        return count;
    }
};