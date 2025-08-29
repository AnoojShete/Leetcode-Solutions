class Solution {
public:
    long long flowerGame(int n, int m) {
        int oddN = (n + 1) / 2, oddM = (m + 1) / 2;
        int evenN = n / 2, evenM = m / 2;
        return (1LL * oddN * evenM) + (1LL * evenN * oddM);
    }
};