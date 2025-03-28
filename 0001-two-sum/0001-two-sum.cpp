class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < v.size(); ++i) {
            int compliment = target - v[i];
            if(mpp.find(compliment) != mpp.end()) return {mpp[compliment], i};
            mpp[v[i]] = i;
        }

        return {-1, -1};
    }
};