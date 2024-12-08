class Solution {
public:
    int maxRectangleArea(vector<vector<int>> &points) {
        int res = -1;
        for (int a = 0; a < points.size(); a++) {
            for (int b = 0; b < points.size(); b++) {
                if (points[a][0] >= points[b][0] || points[a][1] != points[b][1])
                    continue;
                for (int c = 0; c < points.size(); c++) {
                    if (points[a][0] != points[c][0] || points[a][1] >= points[c][1])
                        continue;
                    for (int d = 0; d < points.size(); d++) {
                        if (points[b][0] != points[d][0] || points[c][1] != points[d][1])
                            continue;
                        
                        bool ok = 1;
                        for (int e = 0; e < points.size() && ok; e++)
                            ok &= e == a || e == b || e == c || e == d ||
                                  points[e][0] < points[a][0] || points[d][0] < points[e][0] ||
                                  points[e][1] < points[a][1] || points[d][1] < points[e][1];
                        
                        if (ok)
                            res = max(res, (points[d][0] - points[a][0]) * (points[d][1] - points[a][1]));
                    }
                }
            }
        }
        return res;
    }
};