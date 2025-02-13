class Solution {
public:
    void solve(int n, int index, int &ans, vector<bool> &visited) {
        if(index > n) return;
        for(int i = (index == 1) ? 1 : 0; i < 10; ++i) {
            if(visited[i]) continue;
            visited[i] = true;
            ans++;
            solve(n, index + 1, ans, visited);
            visited[i] = false;
        }
    }
    int countNumbersWithUniqueDigits(int n) {
        int ans = 1;
        vector<bool> visited(10, false);
        solve(n, 1, ans, visited);
        return ans;
    }
};