class Solution {
public:
    bool doesAliceWin(string s) {
        string vowels = "aeiou";
        for(auto ch : s) if(vowels.find(ch) != string::npos) return true;
        return false;
    }
};