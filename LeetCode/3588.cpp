class Solution {
public:
    long long maxArea(vector<vector<int>> &points) {
        unordered_map<int, int> minX, minY, maxX, maxY;
        int globalMinX = 1e9, globalMinY = 1e9, globalMaxX = -1e9, globalMaxY = -1e9;

        for (vector<int> &point : points) {
            int x = point[0], y = point[1];

            if (!minX.count(y) || minX[y] > x)
                minX[y] = x;
            if (!minY.count(x) || minY[x] > y)
                minY[x] = y;
            if (!maxX.count(y) || maxX[y] < x)
                maxX[y] = x;
            if (!maxY.count(x) || maxY[x] < y)
                maxY[x] = y;

            globalMinX = min(globalMinX, x);
            globalMinY = min(globalMinY, y);
            globalMaxX = max(globalMaxX, x);
            globalMaxY = max(globalMaxY, y);
        }

        long long res = 0;
        for (auto &[x, minY] : minY)
            res = max(res, (maxY[x] - minY) * max<long long>(globalMaxX - x, x - globalMinX));
        for (auto &[y, minX] : minX)
            res = max(res, (maxX[y] - minX) * max<long long>(globalMaxY - y, y - globalMinY));
        return res ? res : -1;
    }
};