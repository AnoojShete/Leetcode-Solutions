class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto &token : tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int x = st.top(); st.pop();
                int y = st.top(); st.pop();
                int res;
                if(token == "+") st.push(x + y);
                else if(token == "-") st.push(y - x);
                else if(token == "/") st.push(y / x);
                else st.push(x * y);
            }
            else st.push(stoi(token));
        }
        return st.top();
    }
};