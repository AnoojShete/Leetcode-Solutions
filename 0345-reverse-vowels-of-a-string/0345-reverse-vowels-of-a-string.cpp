class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.length() - 1;
        unordered_set<char> vowels = {'a', 'e', 'o', 'u', 'i', 'A', 'E', 'I', 'O', 'U'};
        while(l < r) {
            while(l < r && !vowels.count(s[l])) l++;
            while(l < r && !vowels.count(s[r])) r--;
            swap(s[l], s[r]);
            l++, r--;
        }

        return s;
    }
};

