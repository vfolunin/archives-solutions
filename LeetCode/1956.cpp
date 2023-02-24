class Solution {
    int dist(int ya, int xa, int yb, int xb) {
        return abs(ya - yb) + abs(xa - xb);
    }

    int kthDist(int y, int x, vector<vector<int>> &points, int k) {
        vector<int> dists(points.size());
        for (int i = 0; i < dists.size(); i++)
            dists[i] = dist(y, x, points[i][0], points[i][1]);
        nth_element(dists.begin(), dists.begin() + k - 1, dists.end());
        return dists[k - 1];
    }

public:
    int minDayskVariants(vector<vector<int>> &points, int k) {
        int res = 1e9;
        for (int y = 1; y <= 100; y++)
            for (int x = 0; x <= 100; x++)
                res = min(res, kthDist(y, x, points, k));
        return res;
    }
};