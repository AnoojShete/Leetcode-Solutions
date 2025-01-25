class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) {
            return  false;
        }
        unordered_map<char, int> mpps1;
        unordered_map<char, int> mpps2;
        
        for(int i = 0; i < s1.length(); i++) {
            mpps1[s1[i]]++;
            mpps2[s2[i]]++;
        }
        if(mpps1 == mpps2) return true;

        int l = 0;
        for(int r = s1.length(); r < s2.length(); r++) {
            mpps2[s2[r]]++;
            mpps2[s2[l]]--;
            if(mpps2[s2[l]] == 0) {
                mpps2.erase(s2[l]);
            }
            l++;
            if(mpps1 == mpps2) return true;
        }

        return false;
    }
};