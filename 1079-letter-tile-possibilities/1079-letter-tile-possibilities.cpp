class Solution {
public:
    void solve(unordered_map<char, int> &mpp, int &count, int length) {
        for(auto &[ch, freq] : mpp) {
            if(freq > 0) {
                count++;
                mpp[ch]--;
                solve(mpp, count, length + 1);
                mpp[ch]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> mpp;
        for(char ch : tiles) {
            mpp[ch]++;
        }
        int count = 0;
        solve(mpp, count, 0);

        return count;
    }
};