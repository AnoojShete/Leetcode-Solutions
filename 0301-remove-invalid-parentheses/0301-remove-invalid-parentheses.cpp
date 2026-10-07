class Solution {
public:
    bool isValid(string &s) {
        int count = 0;
        for(auto ch : s) {
            count += ch == '(';
            count -= ch == ')';
            if(count < 0) return false;
        }
        return count == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        queue<string> q;
        unordered_set<string> st;
        q.push(s);
        st.insert(s);
        bool flag = false;
        vector<string> ans;
        while(!q.empty()) {
            string temp = q.front(); q.pop();
            if(isValid(temp)) {
                ans.push_back(temp);
                flag = true;
            }
            if(flag) continue;
            for(int i = 0; i < temp.size(); ++i) {
                if(temp[i] != '(' && temp[i] != ')') continue;
                string next = temp.substr(0, i) + temp.substr(i + 1);
                if(st.find(next) == st.end()) {
                    q.push(next);
                    st.insert(next);
                }
            }
        }
        return ans;
    }
};