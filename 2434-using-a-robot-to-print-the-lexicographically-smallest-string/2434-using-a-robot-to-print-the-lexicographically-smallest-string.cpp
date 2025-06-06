class Solution {
public:
    char lowestChar(int freq[]) {
        for(int i = 0; i < 26; ++i) if(freq[i]) return 'a' + i;
        return 'a';
    }
    string robotWithString(string s) {
        int freq[26] = {0};
        for(auto ch : s) freq[ch - 'a']++;
        stack<char> st;
        string ans = "";
        for(auto ch : s) {
            st.push(ch);
            freq[ch-'a']--;
            while(!st.empty() && st.top() <= lowestChar(freq)) {
                ans += st.top(); st.pop();
            }
        }
        while(!st.empty()) {
            ans += st.top(); st.pop();
        }
        return ans;
    }
};