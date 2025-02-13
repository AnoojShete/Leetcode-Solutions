class Solution {
public:
    int ans = 0;
    void solve(int n, int index, vector<bool> visited) {
        if(index > n) {
            ans++;
            return;
        }
        for(int i = 1; i <= n; ++i) {
            if(!visited[i] && (i % index == 0 || index % i == 0)) {
                visited[i] = true;
                solve(n, index + 1, visited);
                visited[i] = false;
            }
        }
    }
    int countArrangement(int n) {
        vector<bool> visited(n + 1, false);
        solve(n, 1, visited);
        return ans;
    }
};