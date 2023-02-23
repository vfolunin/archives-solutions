class Solution {
public:
    bool isReflected(vector<vector<int>> &points) {
        int minX = 1e9, maxX = -1e9;
        for (vector<int> &point : points) {
            point[0] *= 2;
            minX = min(minX, point[0]);
            maxX = max(maxX, point[0]);
        }

        int x = minX + (maxX - minX) / 2;
        set<vector<int>> unpaired, paired;

        for (vector<int> &point : points) {
            if (point[0] == x || paired.count(point))
                continue;

            vector<int> reflection = { x * 2 - point[0], point[1] };
            if (unpaired.count(reflection)) {
                unpaired.erase(reflection);
                paired.insert(point);
                paired.insert(reflection);
            } else {
                unpaired.insert(point);
            }
        }

        return unpaired.empty();
    }
};