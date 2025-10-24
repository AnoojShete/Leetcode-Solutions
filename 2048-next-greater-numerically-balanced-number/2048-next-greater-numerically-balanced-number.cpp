class Solution {
public:
    bool isValid(int x) {
        int mpp[10] = {0};
        while(x) {
            mpp[x % 10]++;
            x /= 10;
        }
        for(int i = 0; i < 10; ++i) {
            if(mpp[i] && mpp[i] != i) return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int i = n+1; ; ++i) {
            if(isValid(i)) return i;
        }
        return -1;
    }
};