class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int dom = 0;
        int freq = 0;
        for(auto num : nums) {
            mpp[num]++;
            if(mpp[num] > freq) {
                freq = mpp[num];
                dom = num;
            }
        }
        cout << dom << " " << freq << endl;
        int count = 0;
        for(int i = 0; i < n; ++i) {
            if(nums[i] == dom) count++;
            if((count > (i + 1) / 2) && (freq - count > (n - i - 1) / 2)) return i;
            cout << count << " ";
        }

        return -1;
    }
};