class Solution {
public:
    void solve(string s, vector<string> &temp, vector<string> &ans, unordered_set<string> &dict_set, int index) {
        if(index == s.size()) {
            string res;
            for(int i = 0; i < temp.size(); i++) {
                res += temp[i];
                if(i != temp.size() - 1) res += " ";
            }
            ans.push_back(res);
            return;
        }
        string word;
        for(int i = index; i < s.size(); i++) {
            word += s[i];
            if(dict_set.count(word)) {
                temp.push_back(word);
                solve(s, temp, ans, dict_set, i + 1);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        vector<string> temp;
        unordered_set<string> dict_set;
        for(auto word : wordDict) dict_set.insert(word);

        solve(s, temp, ans, dict_set, 0);

        return ans;
    }
};