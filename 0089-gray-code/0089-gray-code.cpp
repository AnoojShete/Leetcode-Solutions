class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0) return {0};

        vector<int> prev = grayCode(n-1);
        vector<int> ans;

        // First half
        for(auto num : prev) {
            ans.push_back(num);
        }
        // Second half
        for(int i = prev.size() - 1; i >= 0; i--) {
            ans.push_back(prev[i] + (1 << n-1));
        }

        return ans;
    }
};