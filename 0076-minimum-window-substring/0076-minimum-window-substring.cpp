class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> countT;
        unordered_map<char, int> window;
        for(auto ch : t) {
            countT[ch]++;
        }
        int have = 0, need = t.size();
        pair<int, int> pos = {-1, -1};
        int minLen = INT_MAX;
        int l = 0, r = 0;
        while(r < s.size()) {
            char c = s[r];
            window[c]++;
            if(countT.find(c) != countT.end() && window[c] <= countT[c]) have++;

            while(have == need) {
                if(r - l + 1 < minLen) {
                    pos = {l , r};
                    minLen = r - l + 1;
                }
                window[s[l]]--;
                if(countT.find(s[l]) != countT.end() && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
            r++;
        }
        l = pos.first, r = pos.second;
        return minLen == INT_MAX ? "" : s.substr(l, r + 1);
    }
};