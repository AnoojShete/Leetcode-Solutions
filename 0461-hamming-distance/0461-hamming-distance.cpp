class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int d = 0;
        while(z) {
            d += z & 1;
            z >>= 1;
        }
        return d;
    }
};