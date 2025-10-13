class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        int i = 0;
        while(i < n) {
            int j = i + 1;
            string first = words[i];
            while(j < n) {
                string second = words[j];
                bool isAnagram = true;
                int mpp[26] = {0};
                for(auto ch : first) mpp[ch-'a']++;
                for(auto ch : second) mpp[ch-'a']--;
                for(auto it : mpp) if(it) {isAnagram = false; break;}
                if(isAnagram) j++;
                else break;
            }
            ans.push_back(first);
            i = j;
        }
        return ans;
    }
};