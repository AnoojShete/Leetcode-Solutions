class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        int freq[26] = {0};
        bool used[26] = {false};
        for(auto ch : s) freq[ch-'a']++;
        
        for(int i = 0; i < s.length(); ++i) {
            freq[s[i]-'a']--;
            if(used[s[i]-'a']) continue;
            while(!ans.empty() && ans.back() > s[i] && freq[ans.back() - 'a'] > 0) {
                used[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            used[s[i]-'a'] = true;
        }
        return ans;
    }
};