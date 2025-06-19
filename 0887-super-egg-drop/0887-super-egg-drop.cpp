class Solution {
public:
    int t[101][100001];
    int solve(int e, int f) {
        if(f == 0 || f == 1 || e == 1) return f;
        if(t[e][f] != -1) return t[e][f];
        int ans = INT_MAX, l = 1, h = f, temp = 0;
        // Binary Search optimization
        while(l <= h)
        {
            int mid = (l+h)/2;
            int left = solve(e-1, mid-1);
            int right = solve(e, f-mid) ;
            temp = 1 + max(left,right);
            if(left < right) l = mid + 1;
            else h = mid - 1;
            ans = min(ans, temp);
        }
        return t[e][f] = ans;
    }
    int superEggDrop(int e, int f) {
        memset(t, -1, sizeof t);
        return solve(e, f);
    }
};