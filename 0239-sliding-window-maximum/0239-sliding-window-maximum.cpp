class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        deque<int> dq;
        vector<int> ans;
        while(right < n) {
            while(!dq.empty() && dq.back() < nums[right]) {
                dq.pop_back();
            }
            dq.push_back(nums[right]);
            
            if(right - left + 1 < k) right++;
            
            else if(right - left + 1 == k) {
                ans.push_back(dq.front());
                if(dq.front() == nums[left]) dq.pop_front();
                left++, right++;
            }
        }
        
        return ans;
    }
};