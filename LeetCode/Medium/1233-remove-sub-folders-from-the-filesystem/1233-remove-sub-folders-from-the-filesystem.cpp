#define all(a) a.begin(), a.end()

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(all(folder));
        // for(auto s : folder) cout << s << " ";
        vector<string> ans;
        int lastSize = 0;
        for(auto &s : folder) {
            if(!ans.empty() && s.substr(0, lastSize + 1)== ans.back() + "/") continue;
            ans.push_back(s);
            lastSize = s.length();
        }
        return ans;
    }
};