class Solution {
    double getDist(vector<vector<int>> &points, double x, double y) {
        double res = 0;
        for (vector<int> &p : points)
            res += hypot(p[0] - x, p[1] - y);
        return res;
    }
    
    double findY(vector<vector<int>> &points, double x) {
        double l = 0, r = 100;
        for (int i = 0; i < 100; i++) {
            double m1 = l + (r - l) / 3;
            double m2 = r - (r - l) / 3;
            if (getDist(points, x, m1) < getDist(points, x, m2))
                r = m2;
            else
                l = m1;
        }
        return getDist(points, x, l);
    }
    
    double findXY(vector<vector<int>> &points) {
        double l = 0, r = 100;
        for (int i = 0; i < 100; i++) {
            double m1 = l + (r - l) / 3;
            double m2 = r - (r - l) / 3;
            if (findY(points, m1) < findY(points, m2))
                r = m2;
            else
                l = m1;
        }
        return findY(points, l);
    }
    
public:
    double getMinDistSum(vector<vector<int>> &points) {
        return findXY(points);
    }
};