class Solution {
public:
    int numberOfWays(string corridor) {
        int seats = count(corridor.begin(), corridor.end(), 'S');
        if(seats == 0 || seats % 2 == 1) return 0;
        int count = 0;
        int countInbetween = 0;
        long long ans = 1;
        int mod = 1e9 + 7;
        for(int i = 0; i < corridor.size(); ++i) {
            if(corridor[i] == 'S') {
                if(count == 2) {
                    ans = (ans * (countInbetween + 1)) % mod;
                    count = 0;
                    countInbetween = 0;
                }
                count++;
            }
            else if(count == 2) countInbetween++;
        }
        return ans;
    }
};