class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int> q;
        int count = 0;
        for(int i = 0; i < n; ++i) {
            while(!q.empty() && q.front() <= i - k) q.pop();
            if((nums[i] + q.size()) % 2 == 0) {
                if(i + k > n) return -1;
                q.push(i);
                count++;
            }
        }
        return count;
    }
};