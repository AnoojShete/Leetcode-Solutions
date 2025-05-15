class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        queue<int> q;
        q.push(INT_MIN);

        vector<int> ans;
        while(right < n) {
            while(!q.empty() && q.front() < nums[right]) {
                q.pop();
            }
            q.push(nums[right]);
            if(right - left + 1 < k) {
                right++;
            }
            else if(right - left + 1 == k) {
                ans.push_back(q.front());

                if(nums[left] == q.front()) q.pop();
                
                left++, right++;
            }
        }

        return ans;
    }
};