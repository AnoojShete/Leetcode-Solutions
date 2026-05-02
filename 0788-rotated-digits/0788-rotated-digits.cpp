class Solution {
public:
    int rotatedDigits(int n) {
        unordered_map<int, int> mpp = {
            {0, 0}, {1, 1}, {8, 8},
            {2, 5}, {5, 2}, {6, 9}, {9, 6}
        };
        int ans = 0;
        for(int num = 2; num <= n; ++num) {
            int temp = num;
            bool flag = true;
            int rev = 0;
            while(temp) {
                int d = temp % 10;
                if(!mpp.count(d)) {
                    flag = false;
                    break;
                }
                rev = rev * 10 + mpp[d];
                temp /= 10;
            }
            if(flag && rev != revv) ans++;
        }
        return ans;
    }
};