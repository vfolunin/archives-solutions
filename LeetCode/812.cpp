class Solution {
public:
    double largestTriangleArea(vector<vector<int>> &points) {
        int res = 0;
        for (int a = 0; a < points.size(); a++) {
            for (int b = a + 1; b < points.size(); b++) {
                for (int c = b + 1; c < points.size(); c++) {
                    int abx = points[b][0] - points[a][0];
                    int aby = points[b][1] - points[a][1];
                    int acx = points[c][0] - points[a][0];
                    int acy = points[c][1] - points[a][1];
                    res = max(res, abs(abx * acy - aby * acx));
                }
            }
        }
        return res / 2.0;
    }
};