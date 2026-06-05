class Solution {
public:
    struct Node {
        long long cnt;
        long long sum;
    };

    string s;

    Node dp[20][3][11][11][2];
    bool vis[20][3][11][11][2];

    Node dfs(int pos, int state, int last2, int last1, bool tight) {
        if(pos ==(int)s.size()) {
            return {1, 0};
        }

        if(!tight && vis[pos][state][last2][last1][0])
            return dp[pos][state][last2][last1][0];

        int lim = tight ?(s[pos] - '0') : 9;

        Node res{0, 0};

        for(int d = 0; d <= lim; d++) {
            bool ntight = tight &&(d == lim);

            if(state == 0) {
                if(d == 0) {
                    Node nxt = dfs(pos + 1, 0, 10, 10, ntight);
                    res.cnt += nxt.cnt;
                    res.sum += nxt.sum;
                } else {
                    Node nxt = dfs(pos + 1, 1, 10, d, ntight);
                    res.cnt += nxt.cnt;
                    res.sum += nxt.sum;
                }
            }
            else if(state == 1) {
                Node nxt = dfs(pos + 1, 2, last1, d, ntight);
                res.cnt += nxt.cnt;
                res.sum += nxt.sum;
            }
            else {
                int add = 0;

                if((last1 > last2 && last1 > d) ||
                   (last1 < last2 && last1 < d))
                    add = 1;

                Node nxt = dfs(pos + 1, 2, last1, d, ntight);

                res.cnt += nxt.cnt;
                res.sum += nxt.sum + nxt.cnt * add;
            }
        }

        if(!tight) {
            vis[pos][state][last2][last1][0] = true;
            dp[pos][state][last2][last1][0] = res;
        }

        return res;
    }

    long long solve(long long n) {
        if(n < 0) return 0;

        s = to_string(n);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 0, 10, 10, true).sum;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};