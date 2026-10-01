typedef unordered_map<string, vector<pair<string, double>>> graph;

class Solution {
public:
    graph build(vector<vector<string>>& pairs, vector<double>& rates) {
        graph adj;
        for(int i = 0; i < pairs.size(); ++i) {
            string src = pairs[i][0], target = pairs[i][1];
            double rate = rates[i];
            adj[src].push_back({target, rate});
            adj[target].push_back({src, 1/rate});
        }
        return adj;
    }
    unordered_map<string, double> bfs(string start, graph adj, double rate) {
        queue<pair<string, double>> q;
        unordered_map<string, double> mpp;
        q.push({start, rate});
        mpp[start] = rate;
        while(!q.empty()) {
            auto [node, r] = q.front(); q.pop();
            for(auto &[nei, nrate] : adj[node]) {
                double newRate = r * nrate;
                if(mpp[nei] < newRate) {
                    q.push({nei, newRate});
                    mpp[nei] = newRate;
                }
            }
        }
        return mpp;
    }
    double maxAmount(string init, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        graph adj1 = build(pairs1, rates1);
        graph adj2 = build(pairs2, rates2);
        unordered_map<string, double> day1 = bfs(init, adj1, 1.0);
        double ans = 0.0;
        for(auto &[node, rate] : day1) {
            unordered_map<string, double> day2 = bfs(node, adj2, rate);
            ans = max(ans, day2[init]);
        }
        return ans;
    }
};