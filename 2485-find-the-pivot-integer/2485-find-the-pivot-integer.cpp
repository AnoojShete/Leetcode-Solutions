class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n + 1) / 2;
        int currSum = 0;
        for(int i = 1; i <= n; ++i) {
            currSum += i;
            if(currSum == sum - currSum + i) return i;
        }
        return -1;
    }
};