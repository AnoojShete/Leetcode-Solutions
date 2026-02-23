class Solution {
public:
    string makeFancyString(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        string ans = "";
        char prev = '.';
        int count = 0;
        for(auto &ch : s) {
            if(ch != prev) {
                ans.push_back(ch);
                prev = ch;
                count = 1;
            }
            else if(ch == prev && count < 2) {
                ans.push_back(ch);
                count++;
            }
        }
        return ans;
    }
};