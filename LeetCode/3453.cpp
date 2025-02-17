class Solution {
    bool can(vector<vector<int>> &squares, double m) {
        double down = 0, up = 0;
        for (vector<int> &square : squares) {
            if (square[1] <= m)
                down += square[2] * min<double>(m - square[1], square[2]);
            if (m <= square[1] + square[2])
                up += square[2] * min<double>(square[1] + square[2] - m, square[2]);
        }
        return down < up;
    }

public:
    double separateSquares(vector<vector<int>> &squares) {
        double l = 0, r = 2e9;
        for (int i = 0; i < 100; i++) {
            double m = (l + r) / 2;
            if (can(squares, m))
                l = m;
            else
                r = m;
        }
        return l;
    }
};