class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> degree;
        for(int i = 0; i < n; ++i) degree.push_back({0, i});
        for(auto &r : roads) {
            degree[r[0]].first++;
            degree[r[1]].first++;
        }
        sort(degree.rbegin(), degree.rend());
        vector<int> imp(n);
        int i = n;
        for(auto &p : degree) {
            int deg = p.first;
            int node = p.second;
            imp[node] = i;
            i--;
        }

        long long ans = 0;
        for(auto &r : roads) {
            ans += imp[r[0]] + imp[r[1]];
        }

        return ans;
    }
};