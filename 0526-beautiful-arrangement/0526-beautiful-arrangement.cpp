class Solution {
public:
    int ans = 0;

    bool isSolved(int n, int index) {
        return (n % index == 0 ||
                index % n == 0);
    }
    void solve(int n, int index) {
        if(index == n || n < 0) return;
        if(isSolved(n, index)) {
            ans++;
            return;
        }
        for(int i = 1; i < n; ++i) {
            int temp = i;
            i = -1;
            solve(i, index + 1);
            i = temp;
        }
    }
    int countArrangement(int n) {
        solve(n, 1);

        return ans + 1;
    }
};