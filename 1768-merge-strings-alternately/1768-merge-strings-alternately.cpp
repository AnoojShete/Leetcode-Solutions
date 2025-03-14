class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        int l = 0, r = 0;
        string ans = "";
        int it = 0;
        while(l < n1 && r < n2) {
            if(it % 2 == 0) {
                ans += word1[l];
                l++;
            }
            else {
                ans += word2[r];
                r++;
            }
            it++;
        }
        if(l < n1) {
            ans += word1.substr(l, n1);
        }
        else ans += word2.substr(r, n2);

        return ans;
    }
};