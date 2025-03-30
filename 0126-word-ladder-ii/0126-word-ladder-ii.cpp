class Solution {
private:
    void backtrack(string word, string& beginWord, unordered_map<string, vector<string>>& parentMap, 
                   vector<string>& path, vector<vector<string>>& ans) {
        if (word == beginWord) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for (const string& parent : parentMap[word]) {
            path.push_back(parent);
            backtrack(parent, beginWord, parentMap, path, ans);
            path.pop_back();
        }
    }

    bool comp(vector<string> a, vector<string> b) {
        string x = "", y = "";
        for (string i : a) x += i;
        for (string i : b) y += i;
        return x < y;
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return {}; // End word must be in list
        
        unordered_map<string, vector<string>> parentMap;
        queue<string> q;
        unordered_set<string> levelWords;
        bool found = false;
        
        q.push(beginWord);
        st.erase(beginWord);
        
        while (!q.empty() && !found) {
            int size = q.size();
            levelWords.clear();
            
            while (size--) {
                string word = q.front();
                q.pop();
                
                string original = word;
                for (int i = 0; i < word.size(); ++i) {
                    char originalChar = word[i];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        if (ch == originalChar) continue;
                        word[i] = ch;
                        if (st.find(word) != st.end()) {
                            if (levelWords.find(word) == levelWords.end()) {
                                q.push(word);
                                levelWords.insert(word);
                            }
                            parentMap[word].push_back(original);
                            if (word == endWord) found = true;
                        }
                    }
                    word[i] = originalChar;
                }
            }
            
            for (const string& w : levelWords) st.erase(w);
        }

        // If no path found
        if (!found) return {};

        // Backtracking to generate paths
        vector<vector<string>> ans;
        vector<string> path = {endWord};
        backtrack(endWord, beginWord, parentMap, path, ans);
        return ans;
    }
};