typedef long long ll;

class Solution {
public:
    ll largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        ll maxArea = 0;
        for(int i = 0; i < n - 1; ++i) {
            for(int j = i + 1; j < n; ++j) {
                int bx1 = bottomLeft[i][0], by1 = bottomLeft[i][1];
                int tx1 = topRight[i][0], ty1 = topRight[i][1];
                int bx2 = bottomLeft[j][0], by2 = bottomLeft[j][1];
                int tx2 = topRight[j][0], ty2 = topRight[j][1];

                int width  = max(0, min(tx1, tx2) - max(bx1, bx2));
                int height = max(0, min(ty1, ty2) - max(by1, by2));
                int side = min(width, height);

                ll area = 1LL * side * side;

                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};