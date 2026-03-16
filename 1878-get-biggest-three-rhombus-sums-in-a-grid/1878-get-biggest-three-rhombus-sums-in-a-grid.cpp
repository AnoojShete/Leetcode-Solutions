class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dia(m, vector<int>(n));
        vector<vector<int>> anti(m, vector<int>(n));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                dia[i][j] = grid[i][j];
                if(i > 0 && j > 0) dia[i][j] += dia[i-1][j-1];
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = n-1; j >= 0; --j) {
                anti[i][j] = grid[i][j];
                if(i > 0 && j < n-1) anti[i][j] += anti[i-1][j+1];
            }
        }
        set<int> st;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int maxLen = min({i, m-i-1, j, n-j-1});
                for(int len = 0; len <= maxLen; ++len) {
                    if(len == 0) {
                        st.insert(grid[i][j]);
                        continue;
                    }
                    int topX = i-len, topY = j;
                    int leftX = i, leftY = j-len;
                    int rightX = i, rightY = j+len;
                    int bottomX = i+len, bottomY = j;

                    // main dia
                    int ttr = dia[rightX][rightY];
                    if(topX && topY) ttr -= dia[topX-1][topY-1];
                    int ltb = dia[bottomX][bottomY];
                    if(leftX && leftY) ltb -= dia[leftX-1][leftY-1];

                    // anti
                    int ttl = anti[leftX][leftY];
                    if(topX && topY < n-1) ttl -= anti[topX-1][topY+1];
                    int rtb = anti[bottomX][bottomY];
                    if(rightX && rightY < n-1) ltb -= anti[rightX-1][rightY+1];
                    
                    int sum = ttr + ltb + ttl + rtb - grid[topX][topY] - grid[leftX][leftY] - grid[rightX][rightY] - grid[bottomX][bottomY];

                    st.insert(sum);
                }
            }
        }
        vector<int> ans;
        for(auto it = st.rbegin(); it != st.rend() && ans.size() < 3; ++it) {
            ans.push_back(*it);
        }
        return ans;
    }
};