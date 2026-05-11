class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto num : nums) {
            string s = to_string(num);
            for(auto ch : s) ans.push_back(ch - '0');
        }
        return ans;
    }
};