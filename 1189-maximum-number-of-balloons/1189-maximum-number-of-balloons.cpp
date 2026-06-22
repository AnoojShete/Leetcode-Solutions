class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int mpp[26] = {0};
        for(char ch : text) mpp[ch-'a']++;
        return min({mpp[1], mpp[0], mpp[11]/2, mpp[14]/2, mpp[13]});
    }
};