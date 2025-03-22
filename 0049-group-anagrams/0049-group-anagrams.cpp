class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mpp;
        for(auto s:strs){
            string s1 = s;
            sort(s1.begin(),  s1.end());
            mpp[s1].emplace_back(s);
        }
        for(auto v:mpp){
            ans.push_back(v.second);
        }
        return ans;
    }
};