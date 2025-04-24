class Solution {
public:
    vector<vector<int>> adj;
    vector<int> parent, distanceFromRoot;

    void dfs(int node, int par = -1, int dist = 0) {
        parent[node] = par;
        distanceFromRoot[node] = dist;
        for (int neighbor : adj[node]) {
            if (neighbor != par) {
                dfs(neighbor, node, dist + 1);
            }
        }
    }

    int dfsAlice(int node, vector<int>& amount, int par = -1) {
        int currentAmount = amount[node];
        int maxChildProfit = INT_MIN;

        for (int neighbor : adj[node]) {
            if (neighbor != par) {
                maxChildProfit = max(maxChildProfit, dfsAlice(neighbor, amount, node));
            }
        }

        // If it's a leaf node
        if (maxChildProfit == INT_MIN) return currentAmount;

        return currentAmount + maxChildProfit;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        adj.resize(n);
        parent.resize(n);
        distanceFromRoot.resize(n);

        // Build tree
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Step 1: DFS to calculate distance from root and parent of each node
        dfs(0);

        // Step 2: Traverse from Bob to root (node 0) and update amount
        int bobDist = 0;
        int current = bob;
        while (current != -1) {
            if (distanceFromRoot[current] > bobDist) {
                amount[current] = 0;
            } else if (distanceFromRoot[current] == bobDist) {
                amount[current] /= 2;
            }
            current = parent[current];
            bobDist++;
        }

        // Step 3: Run DFS for Alice to find max profit
        return dfsAlice(0, amount);
    }
};
