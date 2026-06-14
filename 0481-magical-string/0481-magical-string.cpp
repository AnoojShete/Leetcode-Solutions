class Solution {
public:
    int magicalString(int n) {
        if(n <= 3) return 1;
        vector<int> s(n + 2);
        s[0] = 1, s[1] = 2, s[2] = 2;
        int head = 2, tail = 3, num = 1;
        int ans = 1;
        while(tail < n) {
            int count = s[head++];
            while(count-- && tail < n) {
                s[tail++] = num;
                if(num == 1) ans++;
            }
            num = 3 - num;
        }
        return ans;
    }
};