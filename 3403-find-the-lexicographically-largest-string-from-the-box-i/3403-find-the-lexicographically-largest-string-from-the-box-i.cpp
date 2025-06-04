class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();
        int len = n - numFriends + 1;
        string ans = "";
        for(int i = 0; i < n; ++i) {
            ans = max(ans, word.substr(i, len));
        }
        return ans;
    }
};