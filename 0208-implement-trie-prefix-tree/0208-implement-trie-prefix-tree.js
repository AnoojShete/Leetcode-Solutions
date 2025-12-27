class Node {
    constructor() {
        this.links = new Array(26).fill(null);
        this.isEnd = false;
    }
    containsKey(ch) {
        return this.links[ch.charCodeAt(0) - 97] != null;
    }
    put(ch, node) {
        this.links[ch.charCodeAt(0) - 97] = node;
    }
    get(ch) {
        return this.links[ch.charCodeAt(0) - 97]; 
    }
    issEnd() {
        return this.isEnd;
    }
    setEnd() {
        this.isEnd = true;
    }
};

var Trie = function() {
    this.root = new Node();
};

Trie.prototype.insert = function(word) {
    let node = this.root;
    for(let i = 0; i < word.length; ++i) {
        const ch = word[i];
        if(!node.containsKey(ch)) node.put(ch, new Node());
        node = node.get(ch);
    }
    node.setEnd();
};

Trie.prototype.search = function(word) {
    let node = this.root;
    for(let i = 0; i < word.length; ++i) {
        const ch = word[i];
        if(!node.containsKey(ch)) return false;
        node = node.get(ch);
    }
    return node.issEnd();
};

Trie.prototype.startsWith = function(prefix) {
    let node = this.root;
    for(let i = 0; i < prefix.length; ++i) {
        const ch = prefix[i];
        if(!node.containsKey(prefix[i])) return false;
        node = node.get(ch);
    }
    return true;
};