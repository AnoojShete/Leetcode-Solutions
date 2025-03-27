class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maj = nums[0];
        for(auto num : nums) {
            if(num == maj) count++;
            else count--;
            if(count == 0) {
                maj = num;
                count = 1;
            }
        }

        int freq = 0;
        for(int i = 0; i < n; ++i) {
            if(nums[i] == maj) freq++;
        }

        count = 0;
        for(int i = 0; i < n; ++i) {
            if(nums[i] == maj) count++;
            if((count > (i + 1) / 2) && (freq - count > (n - i - 1) / 2)) return i;
            cout << count << " ";
        }

        return -1;
    }
};