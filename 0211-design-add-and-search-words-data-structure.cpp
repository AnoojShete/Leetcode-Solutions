struct Node {
    Node* links[27];
    bool flag;

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};

class WordDictionary {
private:
    Node* root;
    bool helper(string word, int idx, Node* node) {
        if(idx == word.size()) return node->isEnd();
        char ch = word[idx];
        if(ch == '.') {
            for(int i = 0; i < 26; ++i) {
                if(node->links[i] && helper(word, idx + 1, node->links[i])) return true;
            }
            return false;
        }
        if(!node->containsKey(ch)) return false;
        return helper(word, idx + 1, node->get(ch));
    }
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(auto ch : word) {
            if(!node->containsKey(ch)) node->put(ch, new Node());
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool search(string word) {
        return helper(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */