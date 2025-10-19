class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> st;
        q.push(s);
        st.insert(s);
        string ans = s;
        while(!q.empty()) {
            auto str = q.front(); q.pop();
            ans = min(ans, str);
            string temp = str;
            for(int i = 1; i < s.length(); i += 2) {
                int x = temp[i]-'0';
                int y = (x + a) % 10;
                temp[i] = '0'+y;
            }
            if(st.find(temp) == st.end()) {
                q.push(temp);
                st.insert(temp);
            }
            temp = str;
            reverse(temp.begin(), temp.begin()+b);
            reverse(temp.begin()+b, temp.end());
            reverse(temp.begin(), temp.end());
            if(st.find(temp) == st.end()) {
                q.push(temp);
                st.insert(temp);
            }
        }
        return ans;
    }
};