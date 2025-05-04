class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mpp;
        int count = 0;
        for(auto &domino : dominoes) {
            if(domino[0] > domino[1]) swap(domino[0], domino[1]);
            count += mpp[{domino[0], domino[1]}];
            mpp[{domino[0], domino[1]}]++;
        }

        return count;
    }
};