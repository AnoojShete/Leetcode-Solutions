class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int even = 0, odd = 0;
        for(int i = 0; i < n; i++) {
            even += 2*i;
            odd += 2*i+1;
        }
        return __gcd(even, odd);
    }
};