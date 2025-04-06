class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        for(int i = 0; i < edges.size() - 1; ++i) {
            if(edges[i][0] == edges[i + 1][1]) return edges[i][0];
        }

        return -1;
    }
};