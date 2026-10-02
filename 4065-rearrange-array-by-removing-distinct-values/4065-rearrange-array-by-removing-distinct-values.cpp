class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int freq[101] = {0};
        for(auto num : nums) freq[num]++;
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 1; j < 101; ++j) {
                if(freq[j] > 0) ans.push_back(j);
                freq[j]--;
            }
        }
        return ans;
    }
};