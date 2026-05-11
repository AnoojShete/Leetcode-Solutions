class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto num : nums) {
            stack<int> st;
            while(num) {
                st.push(num % 10);
                num /= 10;
            }
            while(!st.empty()) ans.push_back(st.top()), st.pop();
        }
        return ans;
    }
};