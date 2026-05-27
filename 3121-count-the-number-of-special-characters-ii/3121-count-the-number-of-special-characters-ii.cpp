class Solution {
public:
    int numberOfSpecialChars(string word) {
        int first[26], last[26];
        memset(first, -1, sizeof first);
        memset(last, -1, sizeof last);
        for(int i = 0; i < word.length(); ++i) {
            char ch = word[i];
            if(islower(ch)) last[ch-'a'] = i;
            else if(first[ch-'A'] == -1) first[ch-'A'] = i;
        }
        int ans = 0;
        for(int i = 0; i < 26; ++i) {
            if(first[i] != -1 && last[i] != -1 && last[i] < first[i]) ans++;
        }
        return ans;
    }
};