class Solution {
public:
    int countLargestGroup(int n) {
        long long mpp[10] = {0};
        long long largest = 0;
        for(int i = 1; i <= n; ++i) {
            int temp = i;
            int sum = 0;
            while(temp) {
                int digit = temp % 10;
                sum += digit;
                temp /= 10;                
            }
            mpp[sum]++;
            largest = max(largest, mpp[sum]);
        }
        int count = 0;
        for(int i = 1; i <= 9; ++i) if(mpp[i] == largest) count++;

        return count;
    }
};