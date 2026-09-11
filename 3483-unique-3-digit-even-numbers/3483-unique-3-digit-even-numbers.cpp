class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int mpp[10] = {0};
        for(auto digit : digits) mpp[digit]++;
        int ans = 0;
        for(int i = 1; i <= 9; ++i) {
            if(mpp[i] == 0) continue;
            mpp[i]--;
            for(int j = 0; j <= 9; ++j) {
                if(mpp[j] == 0) continue;
                mpp[j]--;
                for(int k = 0; k <= 8; k += 2) {
                    if(mpp[k] == 0) continue;
                    mpp[k]--;
                    ans++;
                    mpp[k]++;
                }
                mpp[j]++;
            }
            mpp[i]++;
        }
        return ans;
    }
};