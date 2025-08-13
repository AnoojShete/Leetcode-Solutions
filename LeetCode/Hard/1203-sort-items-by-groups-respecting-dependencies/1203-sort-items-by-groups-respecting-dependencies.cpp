class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, 
    vector<vector<int>>& before) {
        int tot = m;
        for(int i = 0; i < n; ++i) {
            if(group[i] == -1) group[i] = tot++;
        }
        vector<vector<int>> item(n);
        vector<int> itemIndegree(n, 0);
        vector<vector<int>> groups(tot);
        vector<int> groupIndegree(tot, 0);
        for(int v = 0; v < n; ++v) {
            for(auto u : before[v]) {
                item[u].push_back(v);
                itemIndegree[v]++;
                int gu = group[u], gv = group[v];
                if(gu != gv) {
                    groups[gu].push_back(gv);
                    groupIndegree[gv]++;
                }
            }
        }
        queue<int> q;
        for(int i = 0; i < tot; ++i) {
            if(groupIndegree[i] == 0) q.push(i);
        }
        vector<int> order;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            order.push_back(node);
            for(auto it : groups[node]) {
                groupIndegree[it]--;
                if(groupIndegree[it] == 0) q.push(it);
            }
        }
        if(order.size() != tot) return {};

        vector<int> itemOrder;
        while(!q.empty()) q.pop();
        for(int i = 0; i < n; ++i) if(itemIndegree[i] == 0) q.push(i);
        while(!q.empty()) {
            int node = q.front(); q.pop();
            itemOrder.push_back(node);
            for(auto it : item[node]) {
                itemIndegree[it]--;
                if(itemIndegree[it] == 0) q.push(it);
            }
        }
        if(itemOrder.size() != n) return {};
        unordered_map<int, vector<int>> mpp;
        for(auto item : itemOrder) {
            mpp[group[item]].push_back(item);
        }
        vector<int> ans;
        for(auto g : order) {
            for(auto item : mpp[g]) ans.push_back(item);
        }
        return ans;
    }
};