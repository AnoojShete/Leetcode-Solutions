class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        priority_queue<int> maxi;
        priority_queue<int, vector<int>, greater<>> mini;
        auto add = [&](int num) {
            maxi.push(num);
            if(!maxi.empty() && !mini.empty() && maxi.top() > mini.top()) {
                mini.push(maxi.top());
                maxi.pop();
            }
            if(maxi.size() > mini.size() + 1) {
                mini.push(maxi.top());
                maxi.pop();
            }
            else if(mini.size() > maxi.size()) {
                maxi.push(mini.top());
                mini.pop();
            }
        };
        for(auto num : nums1) add(num);
        for(auto num : nums2) add(num);
        if((m + n) & 1) return static_cast<double>(maxi.top());
        return (maxi.top() + mini.top()) / 2.0;
    }
};