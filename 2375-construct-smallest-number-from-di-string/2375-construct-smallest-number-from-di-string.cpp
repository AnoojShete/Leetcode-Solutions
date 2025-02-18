class Solution {
public:
    string smallestNumber(string pattern) {
        string ans = "";
        stack<char> st;
        for(int i = 0; i <= pattern.size(); ++i) {
            st.push('1' + i);
            if(i == pattern.size() || pattern[i] == 'I') {
                while(!st.empty()) {
                    ans += st.top();
                    st.pop();
                }
            }
        }
        return ans;
    }
};