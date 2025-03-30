class Solution {
public:
    vector<int> partitionLabels(string s) {
        int mpp[26] = {0};
        int n = s.length();
        for(int i = 0; i < n; ++i) {
            mpp[s[i] - 'a'] = i;
        }
        vector<int> ans;
        int prev = -1;
        int maxi = 0;
        for(int i = 0; i < n; ++i) {
            maxi = max(maxi, mpp[s[i] - 'a']);
            if(maxi == i) {
                ans.push_back(maxi - prev);
                prev = maxi;
            }
        }
        return ans;
    }
};