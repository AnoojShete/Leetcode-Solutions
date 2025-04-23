class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> mpp(82, 0); 
        int largest = 0;

        for(int i = 1; i <= n; ++i) {
            int temp = i;
            int sum = 0;
            while(temp) {
                sum += temp % 10;
                temp /= 10;
            }
            mpp[sum]++; 
            largest = max(largest, mpp[sum]);  
        }

        int count = 0;
        for(int i = 1; i <= 81; ++i) {
            if(mpp[i] == largest) {
                count++;
            }
        }

        return count;
    }
};
