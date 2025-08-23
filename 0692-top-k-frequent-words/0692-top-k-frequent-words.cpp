struct TrieNode {
    TrieNode* children[26] = {};
    int end = 0;
};

class Trie {
public:
    TrieNode* root;
    Trie() : root(new TrieNode()) {}
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->end++;
    }
    int getFreq(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) return 0;
            node = node->children[idx];
        }
        return node->end; 
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        Trie trie;
        unordered_set<string> st;
        for(auto &word : words) trie.insert(word), st.insert(word);

        auto cmp = [&](const pair<int,string> &a, const pair<int,string> &b) {
            if (a.first == b.first) return a.second < b.second; 
            return a.first > b.first;
        };
        
        priority_queue<pair<int,string>, vector<pair<int,string>>, 
        decltype(cmp)> pq(cmp);

        for(auto word : st) {
            int freq = trie.getFreq(word);
            pq.push({freq, word});
            if(pq.size() > k) pq.pop();
        }
        vector<string> ans;
        while(!pq.empty()) ans.push_back(pq.top().second), pq.pop();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};