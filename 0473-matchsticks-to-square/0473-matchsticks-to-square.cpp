class Solution {
public:
    bool solve(int index, vector<int> &matchsticks, vector<int> &len, int sum) {
        if(index == matchsticks.size()) {
            return (len[0] == len[1] && len[1] == len[2] && len[2] == len[3]);
        }

        for(int i = 0; i < 4; ++i) {
            if(len[i] + matchsticks[index] > sum) continue;
            len[i] += matchsticks[index];
            if(solve(index + 1, matchsticks, len, sum))
                return true;
            len[i] -= matchsticks[index];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() == 0) return false;
        vector<int> len(4, 0);
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        sort(matchsticks.begin(), matchsticks.end(), [](int &a, int &b){return a > b;});
        return solve(0, matchsticks, len, sum / 4);
    }
};