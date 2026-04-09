class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n+1, 0);
        for(auto &shift : shifts) {
            int l = shift[0], r = shift[1], d = shift[2];
            if(d) diff[l] += 1, diff[r+1] -= 1;
            else diff[l] -= 1, diff[r+1] += 1;
        }
        for(int i = 1; i < n; ++i) {
            diff[i] += diff[i-1];
        }
        for(int i = 0; i < n; ++i) {
            s[i] = 'a' + ((s[i] - 'a' + diff[i]) % 26 + 26) % 26;
        }
        return s;
    }
};