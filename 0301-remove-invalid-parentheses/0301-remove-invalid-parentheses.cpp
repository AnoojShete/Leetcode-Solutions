class Solution {
public:
    int isValid(string s) {
        int count = 0;
        for(auto ch : s) {
            if(ch == '(') count++;
            else if(ch == ')') {
                if(count == 0) return false;
                count--;
            }
        }

        return count == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        queue<string> q;
        unordered_set<string> vis;

        q.push(s);
        vis.insert(s);

        bool isFound = false;
        while(!q.empty()) {
            string node = q.front(); q.pop();

            if(isValid(node)) {
                ans.push_back(node);
                isFound = true;
            }

            if(isFound) continue;

            for(int i = 0; i < node.size(); ++i) {
                if(node[i] == ')' || node[i] == '(') {
                    string temp = node.substr(0, i) + node.substr(i + 1);
                    if(vis.find(temp) == vis.end()) {
                        q.push(temp);
                        vis.insert(temp);
                    }
                }
            }
        }

        return ans;
    }
};