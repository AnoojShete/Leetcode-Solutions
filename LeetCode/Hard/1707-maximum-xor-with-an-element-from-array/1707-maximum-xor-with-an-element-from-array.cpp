struct Node {
    Node* links[2];
    
    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }
    void put(int bit, Node* node) {
        links[bit] = node;
    }
    Node* get(int bit) {
        return links[bit];
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for(int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)) node->put(bit, new Node());
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        int maxNum = 0;
        Node* node = root;
        for(int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if(node->containsKey(!bit)) {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<array<int, 3>> sortedQueries;
        for(int i = 0; i < queries.size(); ++i)
            sortedQueries.push_back({queries[i][0], queries[i][1], i});
        sort(sortedQueries.begin(), sortedQueries.end(), [](auto &a, auto &b) {return a[1] < b[1];});
        vector<int> ans(queries.size(), -1);
        Trie trie;
        int idx = 0;
        for(auto q : sortedQueries) {
            int x = q[0], m = q[1], i = q[2];
            bool inserted = false;
            while(idx < nums.size() && nums[idx] <= m) {
                trie.insert(nums[idx]);
                idx++;
                inserted = true;
            }
            ans[i] = inserted ? trie.getMax(x) : -1;
        }
        return ans;
    }
};