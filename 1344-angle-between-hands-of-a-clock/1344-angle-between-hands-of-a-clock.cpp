class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle = abs((double)hour * 5 + (double)minutes / 12 - minutes) * 6;
        return angle > 180 ? 360 - angle : angle;
    }
};