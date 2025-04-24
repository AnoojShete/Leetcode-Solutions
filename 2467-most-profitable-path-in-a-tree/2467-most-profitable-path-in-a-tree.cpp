class Solution {
public:
    int maxProfit = INT_MIN; // final answer

    bool bobTraversal(int node, vector<vector<int>> &adj, 
    vector<bool> &vis, vector<int> &bobSteps, int step) {
        vis[node] = true;
        bobSteps[node] = step;
        if(node == 0) return true;

        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(bobTraversal(it, adj, vis, bobSteps, step + 1)) return true;
            }
        }

        return false;
    }
    void aliceTraversal(int node, vector<vector<int>> &adj, vector<int> &amount,
    vector<bool> &vis, vector<int> &aliceSteps, vector<int> &bobSteps, int step, int amt) {
        vis[node] = true;
        aliceSteps[node] = step;

        // debugging
        // cout << node << " -> " << aliceSteps[node] << " - " << bobSteps[node] << endl;
        
        // If Alice reaches first -> take full amount
        if(aliceSteps[node] < bobSteps[node]) {
            amt += amount[node];
        }
        // If Bob reaches first
        else if(aliceSteps[node] > bobSteps[node]) {
            // nothing as Bob took the full amount
        }
        // If both reaches at same steps -> they'll share equal halfs
        else {
            amt += (amount[node] / 2);
        }

        bool isLeaf = true;

        for(auto it : adj[node]) {
            if(!vis[it]) {
                isLeaf = false;
                aliceTraversal(it, adj, amount, vis, aliceSteps, bobSteps, step + 1, amt);
            }
        }

        if (isLeaf) {
            maxProfit = max(maxProfit, amt); // Update only at leaves
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        // Step 1 : Bob will traverse to Alice
        // Since it's a tree we a single dfs would work
        vector<bool> vis(n, false);
        vector<int> bobSteps(n, INT_MAX); // we will calculate how many steps required by Bob to reach that node

        bobTraversal(bob, adj, vis, bobSteps, 0);
        
        // Step 2: After Bob's traversal, Alice will travel to all the nodes 
        // and we will keep track of maximum profit
        // Same as Bob we will keep track of number of steps
        vector<int> aliceSteps(n, 0);
        vis.assign(n, false);
        aliceTraversal(0, adj, amount, vis, aliceSteps, bobSteps, 0, 0);


        return maxProfit;
    }
};
