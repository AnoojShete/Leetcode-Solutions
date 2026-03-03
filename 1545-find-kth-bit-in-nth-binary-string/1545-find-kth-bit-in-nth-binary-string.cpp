class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        while(--n) {
            string temp = s;
            for(auto &ch : temp) {
                if(ch == '1') ch = '0';
                else ch = '1';
            }
            reverse(temp.begin(), temp.end());
            s.push_back('1');
            s += temp;
        }
        return s[k-1];
    }
};