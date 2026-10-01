class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        x--; y--;
        if (x > y) swap(x, y);

        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            if (i > 0) adj[i].push_back(i - 1);
            if (i < n - 1) adj[i].push_back(i + 1);
        }
        
        if (x != y) {
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> result(n, 0);

        for (int i = 0; i < n; ++i) {
            vector<int> dist(n, -1);
            queue<int> q;
            q.push(i);
            dist[i] = 0;

            while (!q.empty()) {
                int current = q.front();
                q.pop();

                for (int neighbor : adj[current]) {
                    if (dist[neighbor] == -1) {
                        dist[neighbor] = dist[current] + 1;
                        q.push(neighbor);
                    }
                }
            }

            for (int j = 0; j < n; ++j) {
                if (i != j && dist[j] != -1) {
                    int d = dist[j];
                    if (d <= n) {
                        result[d - 1]++;
                    }
                }
            }
        }

        return result;
    }
};