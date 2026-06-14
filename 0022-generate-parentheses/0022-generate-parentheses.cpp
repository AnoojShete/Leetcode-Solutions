class Solution {
public:
    void solve(vector<string> &ans, string out, int o, int c, int n) {
        if(o == 0 && c == 0) {
            ans.push_back(out);
            return;
        }
        if(o) {
            string out1 = out;
            out1 += "(";
            solve(ans, out1, o-1, c, n);
        }
        if(c > o) {
            string out1 = out;
            out1 += ")";
            solve(ans, out1, o, c-1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, "", n, n, n);
        return ans;
    }
};