class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int count = 0;
        int prev = 0;
        for(auto s : bank) {
            int devices = 0;
            for(auto ch : s) {
                if(ch == '1') devices++;
            }
            count += prev * devices;
            if(devices) prev = devices;
        }
        return count;
    }
};