class Solution {
public:
    bool doesAliceWin(string s) {
        string vowels = "aeiou";
        int count = 0;
        for(auto ch : s) if(vowels.find(ch) != string::npos) count++;
        return count != 0;
    }
};