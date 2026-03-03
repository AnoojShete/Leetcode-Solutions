class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';
        int bits = 1 << n;
        int mid = bits / 2;
        if(mid == k) return '1';
        else if(k < mid) return findKthBit(n-1, k);
        else {
            char ch = findKthBit(n-1, bits - k);
            return ch == '0' ? '1' : '0';
        }
    }
};