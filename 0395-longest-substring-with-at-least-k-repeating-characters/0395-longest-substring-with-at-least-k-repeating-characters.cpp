class Solution {
public:
    int solve(const string &s, int k, int left, int right) {
        if(right - left + 1 < k) return 0;

        unordered_map<char, int> mpp;
        for(int i = left; i <= right; ++i) ++mpp[s[i]];

        int mid = left;
        while(mid <= right && mpp[s[mid]] >= k) mid++;

        if(mid > right) return right - left + 1;

        int lMax = solve(s, k, left, mid - 1);
        int rMax = solve(s, k, mid + 1, right);

        return max(lMax, rMax);
    }
    int longestSubstring(string s, int k) {
        return solve(s, k, 0, s.size() - 1);
    }
};