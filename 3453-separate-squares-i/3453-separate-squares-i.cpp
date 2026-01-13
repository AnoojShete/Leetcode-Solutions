class Solution {
public:
    const double EPS = 1e-5;
    double isValid(vector<vector<int>> &squares, double mid) {
        double less = 0, more = 0;
        for(auto &sq : squares) {
            double x = sq[0];
            double bottom = sq[1];
            double l = sq[2];
            double top = bottom + l;
            double area = l * l;
            if(top <= mid) {
                less += area;
            }
            else if(bottom >= mid) {
                more += area;
            }
            // Fraction
            else {
                double belowH = mid - bottom;
                double aboveH = top - mid;
                less += belowH * l;
                more += aboveH * l;
            }
        }
        return less - more;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = -1e18;
        for(auto &sq : squares) {
            low = min(low, (double)sq[1]);
            high = max(high, (double)(sq[1] + sq[2]));
        }
        while(high - low > EPS) {
            const double mid = low + (high - low) / 2.0;
            if(isValid(squares, mid) < 0) low = mid;
            else high = mid;
        }
        return (low + high) / 2.0;
    }
};