class Solution {
public:
    bool isValid(string segment) {
        if (segment.empty() || segment.size() > 3) return false;
        if (segment[0] == '0' && segment.size() > 1) return false;
        int num = stoi(segment);
        return num >= 0 && num <= 255;
    }
    void solve(string &s, string temp, vector<string> &ans, int index, int count) {
        if(count == 3) {
            if(isValid(s.substr(index))) {
                ans.push_back(temp + s.substr(index));
            }
            return;
        }
        for(int i = 1; i <= 3 && index + i < s.size(); i++) {
            string segment = s.substr(index, i);
            if(isValid(segment)) {
                solve(s, temp + segment + ".", ans, index + i, count + 1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string temp;
        solve(s, temp, ans, 0, 0);

        return ans;
    }
};