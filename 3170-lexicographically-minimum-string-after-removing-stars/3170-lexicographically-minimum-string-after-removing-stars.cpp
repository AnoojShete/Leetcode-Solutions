class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
        vector<bool> keep(s.length(), true);
        for(int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if(ch != '*') {
                pq.push({ch, -i});
            }
            else {
                auto [x, idx] = pq.top(); pq.pop();
                keep[i] = false;
                keep[-idx] = false;
            }
        }
        string ans = "";
        for(int i = 0; i < s.length(); ++i) {
            if(keep[i]) ans += s[i];
        }
        return ans;
    }
};