class Solution {
public:
    void solve(string digits, int index, unordered_map<char, string> &mpp, string &temp, vector<string> &ans) {
        if(index == digits.size()) {
            ans.push_back(temp);
            return;
        }
        char chr = digits[index];
        for(char letter : mpp[chr]) {
            temp += letter;
            solve(digits, index + 1, mpp, temp, ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";

        vector<string> ans;
        string temp = "";
        if(digits.size())
            solve(digits, 0, mpp, temp, ans);

        return ans;
    }
};