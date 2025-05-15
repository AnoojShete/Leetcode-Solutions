class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_set<int> st;
        for(auto it : nums) st.insert(it);

        for(int i = 1; i <= n; ++i) {
            if(st.find(i) == st.end()) ans.push_back(i);
        }

        return ans;
    }
};