class Solution {
public:
    string clearStars(string s) {
        priority_queue<char, vector<char>, greater<char>> pq;
        unordered_map<char, vector<int>> mpp;
        vector<bool> keep(s.length(), true);
        for(int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if(ch != '*') {
                pq.push(ch);
                mpp[ch].push_back(i);
            }
            else {
                auto x = pq.top(); pq.pop();
                int idx = mpp[x].back();
                mpp[x].pop_back();
                keep[i] = false;
                keep[idx] = false;
            }
        }
        string ans = "";
        for(int i = 0; i < s.length(); ++i) {
            if(keep[i]) ans += s[i];
        }
        return ans;
    }
};