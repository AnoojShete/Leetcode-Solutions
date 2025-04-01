class Solution {
public:
    long long solve(int index, vector<vector<int>> &questions, int n) {
        if(index == n - 1) return questions[index][0];
        if(index >= n) return 0;

        return max(questions[index][0] + solve(index + questions[index][1] + 1, questions, n),
        solve(index + 1, questions, n));
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        return solve(0, questions, n);
    }
};