class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(auto word : words) {
            int sum = 0;
            for(auto ch : word) sum += weights[ch-'a'];
            ans.push_back('z' - sum % 26);
        }
        return ans;
    }
};