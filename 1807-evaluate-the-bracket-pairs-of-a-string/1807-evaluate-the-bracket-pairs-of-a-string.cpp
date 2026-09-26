class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;
        for(auto v : knowledge) {
            string a = v[0], b = v[1];
            mpp[a] = b;
        }
        string ans;
        bool flag = false;
        string temp;
        for(char ch : s) {
            if(ch == '(') flag = true;
            else if(ch == ')') {
                cout << temp << '\n';
                ans += mpp.find(temp) == mpp.end() ? "?" : mpp[temp];
                flag = false;
                temp.clear();
            }
            else {
                if(flag) temp.push_back(ch);
                else ans.push_back(ch);
            }
        }
        return ans;
    }
};