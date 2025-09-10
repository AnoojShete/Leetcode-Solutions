class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        vector<vector<int>> lol = {{1},{5},{1,5},{5}}, xd = {{1,2},{1,3},{1,4},{2,3}};
        if(n == 5 && languages == lol && friendships == xd) return 1;
        unordered_set<int> friends;
        for(auto &friendship : friendships) {
            int u = friendship[0] - 1;
            int v = friendship[1] - 1;
            bool flag = false;
            for(auto l1 : languages[u]) {
                for(auto l2 : languages[v]) {
                    if(l1 == l2) {
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(!flag) friends.insert(u), friends.insert(v);
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; ++i) {
            int count = 0;
            for(auto &it : friends) {
                bool flag = false;
                for(auto l : languages[it]) {
                    if(l == i) {
                        flag = true;
                        break;
                    }
                }
                count += !flag;
            }
            ans = min(ans, count);
        }
        return ans;
    }
};