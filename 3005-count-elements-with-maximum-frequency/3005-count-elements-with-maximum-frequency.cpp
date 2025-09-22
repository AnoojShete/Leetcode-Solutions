class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101] = {0};
        int maxi = 0;
        for(auto num : nums) maxi = max(maxi, ++freq[num]);
        int ans = 0;
        for(auto num : freq) if(freq[num] == maxi) ans++;
        return ans;
    }
};