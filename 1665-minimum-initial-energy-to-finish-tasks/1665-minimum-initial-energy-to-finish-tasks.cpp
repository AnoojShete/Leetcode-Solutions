#define all(a) a.begin(), a.end()

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(all(tasks), [](auto a, auto b) {
            return a[1] - a[0] > b[1] - b[0];
        });
        int start = tasks[0][1];
        int bal = tasks[0][1] - tasks[0][0];
        int loan = 0;
        for(int i = 1; i < tasks.size(); ++i) {
            int cost = tasks[i][0];
            int threshold = tasks[i][1];
            if(bal < threshold) {
                loan += threshold - bal;
                bal = threshold;
            }
            bal -= cost;
        }
        return start + loan;
    }
};