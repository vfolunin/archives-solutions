class Solution {
    bool isRegion(vector<vector<int>> &a, int y0, int x0, int limit) {
        for (int y = 0; y < 3; y++)
            for (int x = 0; x < 3; x++)
                if ((y + 1 < 3 && abs(a[y0 + y][x0 + x] - a[y0 + y + 1][x0 + x]) > limit) ||
                    (x + 1 < 3 && abs(a[y0 + y][x0 + x] - a[y0 + y][x0 + x + 1]) > limit))
                    return 0;
        return 1;
    }

    int averageIntensity(vector<vector<int>> &a, int y0, int x0) {
        int sum = 0;
        for (int y = 0; y < 3; y++)
            for (int x = 0; x < 3; x++)
                sum += a[y0 + y][x0 + x];
        return sum / 9;
    }

public:
    vector<vector<int>> resultGrid(vector<vector<int>> &a, int limit) {
        int h = a.size(), w = a[0].size();
        vector<vector<vector<int>>> intensities(h, vector<vector<int>>(w));

        for (int y0 = 0; y0 + 3 <= h; y0++) {
            for (int x0 = 0; x0 + 3 <= w; x0++) {
                if (!isRegion(a, y0, x0, limit))
                    continue;

                int intensity = averageIntensity(a, y0, x0);
                for (int y = 0; y < 3; y++)
                    for (int x = 0; x < 3; x++)
                        intensities[y0 + y][x0 + x].push_back(intensity);
            }
        }

        vector<vector<int>> res(h, vector<int>(w));
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (intensities[y][x].empty()) {
                    res[y][x] = a[y][x];
                } else {
                    for (int intensity : intensities[y][x])
                        res[y][x] += intensity;
                    res[y][x] /= intensities[y][x].size();
                }
            }
        }
        return res;
    }
};