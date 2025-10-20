class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(auto &op : operations) {
            if(op[0] == 'X') {
                if(op.back() == '+') x++;
                else x--;
            } else {
                if(op.front() == '+') x++;
                else x--;
            }
        }
        return x;
    }
};