class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<>> pq;
        for (auto num : nums) {
            if (pq.size() < k)
                pq.push(num);
            else {
                if (pq.top() < num) {
                    pq.pop();
                    pq.push(num);
                }
            }
        }
        unordered_map<int, int> mpp;
        while (!pq.empty()) {
            mpp[pq.top()]++;
            pq.pop();
        }
        for (auto num : nums)
            if (mpp[num]) {
                mpp[num]--;
                ans.push_back(num);
            }
        return ans;
    }
};