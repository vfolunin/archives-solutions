class Solution {
    double findX(double oy, double ox, double y, double x1, double x2) {
        for (int i = 0; i < 100; i++) {
            double m1 = x1 + (x2 - x1) / 3;
            double m2 = x2 - (x2 - x1) / 3;
            
            double d1 = hypot(ox - m1, oy - y);
            double d2 = hypot(ox - m2, oy - y);
            
            if (d1 < d2)
                x2 = m2;
            else
                x1 = m1;
        }
        return x1;
    }
    
    pair<double, double> findYX(double oy, double ox, double y1, double y2, double x1, double x2) {
        for (int i = 0; i < 100; i++) {
            double m1 = y1 + (y2 - y1) / 3;
            double m2 = y2 - (y2 - y1) / 3;
            
            double d1 = hypot(ox - findX(oy, ox, m1, x1, x2), oy - m1);
            double d2 = hypot(ox - findX(oy, ox, m2, x1, x2), oy - m2);
            
            if (d1 < d2)
                y2 = m2;
            else
                y1 = m1;
        }
        return { y1, findX(oy, ox, y1, x1, x2) };
    }
    
public:
    bool checkOverlap(int r, int ox, int oy, int x1, int y1, int x2, int y2) {
        auto [y, x] = findYX(oy, ox, y1, y2, x1, x2);
        return hypot(ox - x, oy - y) <= r + 1e-9;
    }
};