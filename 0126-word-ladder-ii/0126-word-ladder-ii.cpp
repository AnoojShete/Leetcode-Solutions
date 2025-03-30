class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> used;
        used.push_back(beginWord);
        vector<vector<string>> ans;
        int level = 0;
        while(!q.empty()) {
            auto seq = q.front();
            q.pop();
            string word = seq.back();
            if(seq.size() > level) {
                level++;
                for(auto it : used) st.erase(it);
                used.clear();
            }
            if(word == endWord) {
                if(ans.empty() || ans[0].size() == seq.size()) {
                    ans.push_back(seq);
                }
            }
            for(int i = 0; i < word.size(); ++i) {
                char og = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        seq.push_back(word);
                        q.push(seq);
                        used.push_back(word);
                        seq.pop_back();
                    }
                }
                word[i] = og;
            }
        }

        return ans;
    }
};