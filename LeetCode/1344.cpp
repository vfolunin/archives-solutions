class Solution {
public:
    double angleClock(int h, int m) {
        double ha = (h % 12 * 60 + m) / 720.0 * 360;
        double ma = m / 60.0 * 360;
        double a = abs(ha - ma);
        return min(a, 360 - a);
    }
};