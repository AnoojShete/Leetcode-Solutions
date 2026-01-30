struct Node {
    Node* links[26];
    int id = -1;

    bool containsKey(char ch) {
        return links[ch-'a'] != nullptr;
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node;
    }
    Node* get(char ch) {
        return links[ch-'a'];
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(string s, int id) {
        Node* temp = root;
        for(auto ch : s) {
            if(!temp->containsKey(ch)) temp->put(ch, new Node());
            temp = temp->get(ch);
        }
        temp->id = id;
    }
};

class Solution {
public:
    long long minimumCost(string source, string target,vector<string>& original, vector<string>& changed, vector<int>& cost) {
        const long long INF = 1e18;
        unordered_map<string, int> id;
        int idx = 0;

        for(int i = 0; i < original.size(); i++) {
            if(!id.count(original[i])) id[original[i]] = idx++;
            if(!id.count(changed[i]))  id[changed[i]]  = idx++;
        }

        int n = idx;
        vector<vector<long long>> dist(n, vector<long long>(n, INF));

        for(int i = 0; i < n; i++)
            dist[i][i] = 0;

        for(int i = 0; i < original.size(); i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v],(long long)cost[i]);
        }
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];

        Trie trie;
        for(auto& [s, i] : id)
            if(find(original.begin(), original.end(), s) != original.end())
                trie.insert(s, i);

        int m = source.size();
        vector<long long> dp(m + 1, INF);
        dp[m] = 0;

        for(int i = m - 1; i >= 0; i--) {
            Node* cur = trie.root;
            for(int j = i; j < m; j++) {
                char c = source[j];
                if(!cur->containsKey(c)) break;
                cur = cur->get(c);

                if(cur->wordId != -1) {
                    int len = j - i + 1;
                    string tgt = target.substr(i, len);

                    if(id.count(tgt)) {
                        int v = id[tgt];
                        long long cst = dist[cur->wordId][v];
                        if(cst < INF)
                            dp[i] = min(dp[i], cst + dp[j + 1]);
                    }
                }
            }
        }

        return dp[0] == INF ? -1 : dp[0];
    }
};