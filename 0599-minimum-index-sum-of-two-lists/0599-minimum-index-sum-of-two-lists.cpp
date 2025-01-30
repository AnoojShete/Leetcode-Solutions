class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mpp;
        for(int i = 0; i < list1.size(); i++) {
            mpp[list1[i]] = i;
        }
        
        map<int, vector<string>> mpp2;
        for(int i = 0; i < list2.size(); i++) {
            if(mpp.find(list2[i]) != mpp.end()) {
                mpp2[i + mpp[list2[i]]].push_back(list2[i]);
            }
        }

        return mpp2.begin()->second;
    }
};