class Solution {
    int getShapeCount(unordered_map<double, vector<double>> &shapes) {
        int res = 0;

        for (auto &[_, values] : shapes) {
            unordered_map<double, int> valueCount;
            for (double value : values)
                valueCount[value]++;

            int prevTotalCount = 0;
            for (auto &[_, count] : valueCount) {
                res += prevTotalCount * count;
                prevTotalCount += count;
            }
        }

        return res;
    }

public:
    int countTrapezoids(vector<vector<int>> &points) {
        unordered_map<double, vector<double>> trapezoids, parallelograms;

        for (int ai = 0; ai < points.size(); ai++) {
            double ax = points[ai][0], ay = points[ai][1];

            for (int bi = ai + 1; bi < points.size(); bi++) {
                double bx = points[bi][0], by = points[bi][1];

                double k = 1e9, b = ax;
                if (ax != bx) {
                    k = (by - ay) / (bx - ax);
                    b = (ay * (ax - bx) - ax * (ay - by)) / (ax - bx);
                }
                trapezoids[k].push_back(b);

                double midpoint = (ax + bx) / 2 * 1e4 + (ay + by) / 2;
                parallelograms[midpoint].push_back(k);
            }
        }

        return getShapeCount(trapezoids) - getShapeCount(parallelograms);
    }
};