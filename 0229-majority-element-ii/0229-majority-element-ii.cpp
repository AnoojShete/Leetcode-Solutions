class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cand1, cand2;
        int c1 = 0, c2 = 0;
        for(int i = 0; i < n; ++i) {
            if(c1 == 0 && nums[i] != cand2) {
                c1 = 1; cand1 = nums[i];
            }
            else if(c2 == 0 && nums[i] != cand1) {
                c2 = 1; cand2 = nums[i];
            }
            else if(nums[i] == cand1) c1++;
            else if(nums[i] == cand2) c2++;
            else c1--, c2--;
        }
        int count1 = count(nums.begin(), nums.end(), cand1);
        int count2 = count(nums.begin(), nums.end(), cand2);
        vector<int> ans;
        if(count1 > n/3) ans.push_back(cand1);
        if(count2 > n/3) ans.push_back(cand2);
        return ans;
    }
};