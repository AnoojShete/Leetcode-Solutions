class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int zero = 0, one = 0, two = 0;
        for(auto stone : stones) {
            if(stone % 3 == 0) zero++;
            else if(stone % 3 == 1) one++;
            else two++;
        }
        if(zero % 2 == 0) return min(one, two) >= 1;
        return abs(one - two) > 2;
    }
};