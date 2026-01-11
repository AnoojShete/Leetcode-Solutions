class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }

            stack<int> st;
            vector<int> left(n), right(n);

            for (int j = n - 1; j >= 0; --j) {
                while (!st.empty() && heights[st.top()] >= heights[j]) st.pop();
                right[j] = st.empty() ? n : st.top();
                st.push(j);
            }

            while (!st.empty()) st.pop();

            for (int j = 0; j < n; ++j) {
                while (!st.empty() && heights[st.top()] >= heights[j]) st.pop();
                left[j] = st.empty() ? -1 : st.top();
                st.push(j);
            }

            for (int j = 0; j < n; ++j) {
                int area = heights[j] * (right[j] - left[j] - 1);
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
