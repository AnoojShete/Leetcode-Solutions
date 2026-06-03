class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        vector<string> tokens;
        string curr;
        for(int i = 0; i < n; ++i) {
            if(path[i] == '/') {
                if(!curr.empty()) {
                    tokens.push_back(curr);
                    curr.clear();
                }
            }
            else curr.push_back(path[i]);
        }
        if(!curr.empty()) tokens.push_back(curr);
        vector<string> st;
        for(auto token : tokens) {
            if(token == ".") continue;
            if(token == "..") {if(!st.empty()) st.pop_back();}
            else st.push_back(token);
        }
        string ans = "/";
        for(auto s : st) ans += (s + "/");
        if(ans.length() != 1) ans.pop_back();
        return ans;
    }
};