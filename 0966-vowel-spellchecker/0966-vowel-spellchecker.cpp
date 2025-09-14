class Solution {
public:
    string toLow(string word) {
        string s;
        for (auto ch : word) s.push_back(tolower(ch));
        return s;
    }

    string helper(string word) {
        string toLower = toLow(word);
        string noVowel;
        for (char ch : toLower) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                noVowel.push_back('*');
            else
                noVowel.push_back(ch);
        }
        return noVowel;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> low;
        unordered_map<string, string> vowel;

        for (auto& word : wordlist) {
            string lower = toLow(word);
            string vow = helper(word);
            if (low.find(lower) == low.end()) low[lower] = word;
            if (vowel.find(vow) == vowel.end()) vowel[vow] = word;
        }

        vector<string> ans;
        for (auto& query : queries) {
            if (exact.count(query)) {
                ans.push_back(query);
            } else {
                string lower = toLow(query);
                string vow = helper(query);
                if (low.count(lower)) {
                    ans.push_back(low[lower]);
                } else if (vowel.count(vow)) {
                    ans.push_back(vowel[vow]);
                } else {
                    ans.push_back("");
                }
            }
        }

        return ans;
    }
};
