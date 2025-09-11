class Solution {
public:
    string sortVowels(string s) {
        string vow;
        string vowels = "aeiouAEIOU";
        for(auto ch : s) {
            if(vowels.find(ch) != string::npos) vow.push_back(ch);
        }
        sort(vow.begin(), vow.end());
        int idx = 0;
        for(auto &ch : s) {
            if(vowels.find(ch) != string::npos) {
                ch = vow[idx++];
            }
        }
        return s;
    }
};