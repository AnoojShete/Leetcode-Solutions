#define all(a) a.begin(), a.end()

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> mpp;
        for(int i = 0; i < n; ++i) mpp[words[i]] = i;

        auto isPalin = [&](const string &s) {
            int i = 0, j = s.length()-1;
            while(i < j) if(s[i++] != s[j--]) return false;
            return true;
        };
        vector<vector<int>> ans;
        for(int i = 0; i < n; ++i) {
            string word = words[i];
            for(int k = 0; k <= word.length(); ++k) {
                string left = word.substr(0, k);
                string right = word.substr(k);
                if(isPalin(left)) {
                    string rev = right;
                    reverse(all(rev));
                    if(mpp.find(rev) != mpp.end() && mpp[rev] != i) ans.push_back({mpp[rev], i});
                }
                if(!right.empty() && isPalin(right)) {
                    string rev = left;
                    reverse(all(rev));
                    if(mpp.find(rev) != mpp.end() && mpp[rev] != i) ans.push_back({i, mpp[rev]});
                }
            }
        }
        return ans;
    }
};