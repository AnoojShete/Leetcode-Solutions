class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int, int> mpp;
        for(auto x : nums) mpp[x]++;
        vector<int> ans;
        while(!mpp.empty()) {
            for(auto it = mpp.begin(); it != mpp.end();) {
                ans.push_back(it->first);
                if(--it->second == 0) it = mpp.erase(it);
                else ++it;
            }
        }
        return ans;
    }
};