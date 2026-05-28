struct Node {
    Node* links[26] = {nullptr};
    int idx = -1;

    bool containsKey(char ch) {
        return links[ch-'a'] != nullptr;
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node;
    }
    Node* get(char ch) {
        return links[ch-'a'];
    }
    ~Node() {
        for(int i = 0; i < 26; ++i) if(links[i] != nullptr) delete links[i], links[i] = nullptr;
    }
};

class Trie {
private:
    Node* root;
    vector<string> &wordsContainer;
public:
    Trie(vector<string> &wc) : wordsContainer(wc) {
        root = new Node();
    }
    ~Trie() {
        delete root;
    }
    bool cmp(int newIdx, int oldIdx) {
        if(wordsContainer[newIdx].length() != wordsContainer[oldIdx].length())
            return wordsContainer[newIdx].length() < wordsContainer[oldIdx].length();
        return newIdx < oldIdx;
    }
    void insert(string s, int i) {
        Node* node = root;
        if(node->idx == -1 || cmp(i, node->idx)) node->idx = i;
        for(int j = s.length()-1; j >= 0; --j) {
            char ch = s[j];
            if(!node->containsKey(ch)) node->put(ch, new Node());
            node = node->get(ch);
            if(node->idx == -1 || cmp(i, node->idx)) node->idx = i;
        }
    }
    int search(string s) {
    Node* node = root;
    for(int j = s.length()-1; j >= 0; --j) {
        char ch = s[j];
        if(!node->containsKey(ch)) break;
        node = node->get(ch);
    }
    return node->idx;
}
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int> ans;
        Trie trie(wordsContainer);
        for(int i = 0; i < wordsContainer.size(); ++i) {
            string word = wordsContainer[i];
            trie.insert(word, i);
        }
        for(auto q : wordsQuery) {
            ans.push_back(trie.search(q));
        }
        return ans;
    }
};