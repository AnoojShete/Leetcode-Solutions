class DisjointSet {
    vector<int> parent;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }

    void unionByIndex(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if(root_u != root_v) parent[root_v] = root_u;
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> indexedNums;
        for(int i = 0; i < n; ++i) {
            indexedNums.push_back({nums[i], i});
        }
        sort(indexedNums.begin(), indexedNums.end());
        
        DisjointSet ds(n);
        for(int i = 0; i < n; ++i) {
            int a = indexedNums[i].first;
            int b = indexedNums[i + 1].first;
            if(abs(a - b) <= limit) {
                ds.unionByIndex(indexedNums[i].second, indexedNums[i + 1].second);
            }
        }
        unordered_map<int, vector<int>> mpp;
        unordered_map<int, vector<int>> mppIndices;
        for(int i = 0; i < n; ++i) {
            int minIndex = ds.find(i);
            mpp[minIndex].push_back(nums[i]);
            mppIndices[minIndex].push_back(i);
        }
        for(auto &[idx, vals] : mpp) {
            vector<int> indices = mppIndices[idx];
            sort(vals.begin(), vals.end());
            for(int i = 0; i < vals.size(); ++i) {
                nums[indices[i]] = vals[i];
            }
        }
        return nums;
    }
};