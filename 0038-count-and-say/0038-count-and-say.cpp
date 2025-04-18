class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1"; // base condition
        
        string temp = countAndSay(n - 1); // hypothesis

        // induction
        string next = "";
        int count = 1;
        for(int i = 1; i < temp.size(); ++i) {
            if(temp[i - 1] == temp[i]) count++;
            else {
                next += to_string(count) + temp[i - 1];
                count = 1;
            }
        }
        next += to_string(count) + temp[temp.size() - 1];
        return next;
    }
};