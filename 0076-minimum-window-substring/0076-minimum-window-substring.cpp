class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if(m < n) return "";
        unordered_map<char, int> sMpp, tMpp;
        int count = 0;
        for(auto ch : t) {
            if(tMpp[ch] == 0) count++;
            tMpp[ch]++;
        }
        int i = 0;
        int minLen = INT_MAX;
        int start = -1, end = -1;
        for(int j = 0; j < m; ++j) {
            sMpp[s[j]]++;
            if(tMpp[s[j]] > 0 && sMpp[s[j]] == tMpp[s[j]]) count--;
            while(count == 0) {
                if(minLen > j - i + 1) {
                    minLen = j - i + 1;
                    start = i, end = j;
                }
                if(tMpp[s[i]] > 0 && sMpp[s[i]] == tMpp[s[i]]) count++;
                sMpp[s[i]]--;
                i++;
            }
        }
        return start == -1 && end == -1 ? "" : s.substr(start, end - start + 1);
    }
};