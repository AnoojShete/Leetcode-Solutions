struct Node {
    Node* links[26];
    bool  flag = false;

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

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    void insert(string &word) {
        Node* node = root;
        for(auto ch : word) {
            if(!node->containsKey(ch)) node->put(ch, new Node());
            node = node->get(ch);
        }
        node->setEnd();
    }
    string prefix(string &word) {
        Node* node = root;
        string pre = "";
        for(auto ch : word) {
            if(!node->containsKey(ch)) break;
            node = node->get(ch);
            pre.push_back(ch);
            if(node->isEnd()) return pre;
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(auto &word : dictionary) trie.insert(word);
        stringstream ss(sentence);
        string word;
        string ans = "";
        while(ss >> word) {
            ans += trie.prefix(word);
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};