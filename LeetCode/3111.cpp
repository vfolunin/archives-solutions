class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>> &points, int w) {
        sort(points.begin(), points.end());

        int from = -2e9, res = 0;
        for (vector<int> &point : points) {
            if (from + w < point[0]) {
                from = point[0];
                res++;
            }
        }

        return res;
    }
};