class Solution {
public:
    int countCoveredBuildings(int size, vector<vector<int>> &points) {
        unordered_map<int, int> minX, minY, maxX, maxY;
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
        }
        
        int res = 0;
        for (vector<int> &point : points) {
            int x = point[0], y = point[1];
            res += minX[y] < x && x < maxX[y] && minY[x] < y && y < maxY[x];
        }
        return res;
    }
};