class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Dutch National Flag Algorigthm
        int low = 0, mid = 0, high = nums.size() - 1;
        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                mid++, low++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        /*
        Old solution: O(2N) TC
        int zeros = 0;
        int ones = 0;
        int twos = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) {
                zeros++;
            }
            if(nums[i] == 1) {
                ones++;
            }
            if(nums[i] == 2) {
                twos++;
            }
        }
        for(int i=0; i<zeros; i++) {
            nums[i] = 0;
        }
        for(int i=zeros; i<zeros+ones; i++) {
            nums[i] = 1;
        }
        for(int i=zeros+ones; i<nums.size(); i++) {
            nums[i] = 2;
        }
        */
    }
};