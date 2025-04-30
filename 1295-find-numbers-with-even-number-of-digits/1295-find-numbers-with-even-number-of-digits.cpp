class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(auto num : nums) {
            int digits = 0;
            while(num) {
                digits++;
                num /= 10;
            }
            count += digits % 2 == 0 ? 1 : 0; 
        }

        return count;
    }
};