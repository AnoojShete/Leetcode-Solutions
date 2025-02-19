class Solution {
public:
    void solve(int n, int k, string &temp, string &ans, int &count) {
        // if string size == n
        if(temp.size() == n) {
            count++;
            // k th
            if(count == k) {
                ans = temp;
            }
            return;
        }
        for(auto ch : {'a', 'b', 'c'}) {
            if(temp.empty() || ch != temp.back()) {
                temp += ch;
                solve(n, k, temp, ans, count);
                if(!ans.empty()) return;
                temp.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        string ans = "";
        string temp = "";
        int count = 0;
        solve(n, k, temp, ans, count);

        return ans;
    }
};