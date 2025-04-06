class Solution {
public:
    int numSquares(int n) {
        // B-F-S
        queue<int> q;

        q.push(n);
        int level = 0;
        while(!q.empty()) {
            int len = q.size();
            for(int i = 0; i < len; ++i) {
                int node = q.front();
                if(node == 0) return level;
                q.pop();
                for(int j = 1; j <= sqrt(n); ++j) {
                    q.push(node - j * j);
                }
            }
            level++;
        }
        return -1;
    }
};