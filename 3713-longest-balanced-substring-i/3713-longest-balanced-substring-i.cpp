class Solution {
public:
    bool isValid(unordered_map<char, int> &mpp) {
        int c = -1;
        for(auto &[num, f] : mpp) {
            if(c == -1) c = f;
            else if(c != f) return false;
        }
        return true;
    }
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            unordered_map<char, int> mpp;
            for(int j = i; j < n; ++j) {
                mpp[s[j]]++;
                if(isValid(mpp)) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};