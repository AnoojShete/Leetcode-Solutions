class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, bool> mpp;
        int count = 0;
        for(auto ch : arr) {
            if(mpp.count(ch)) {
                mpp[ch] = false;
            }
            else mpp[ch] = true;
        }
        for(auto ch : arr) {
            if(mpp[ch]) {
                count++;
                if(count == k) return ch;
            }
        }

        return "";
    }
};