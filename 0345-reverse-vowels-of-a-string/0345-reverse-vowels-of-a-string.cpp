class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.length() - 1;
        unordered_set<char> vowels = {'a', 'e', 'o', 'u', 'i', 'A', 'E', 'I', 'O', 'U'};
        while(l <= r) {
            while(l < r && vowels.find(s[l]) == vowels.end()) l++;
            while(l < r && vowels.find(s[r]) == vowels.end()) r--;
            swap(s[l], s[r]);
            l++, r--;
        }

        return s;
    }
};

