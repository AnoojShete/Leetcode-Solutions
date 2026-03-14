class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3 * (1 << (n-1));
        char prev = 'x';
        string ans;
        for(int i = 0; i < n; ++i) {
            for(auto ch : {'a', 'b', 'c'}) {
                if(ch == prev) continue;
                int count = 1 << (n-i-1);
                if(k > count) k -= count;
                else {
                    ans.push_back(ch);
                    prev = ch;
                    break;
                }
            }
        }
        return ans.size() == n ? ans : "";
    }
};