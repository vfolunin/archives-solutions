class Solution {
public:
    vector<long long> countOfPairs(int vertexCount, int a, int b) {
        vector<long long> res(vertexCount);

        if (abs(a - b) <= 1) {
            for (int dist = 1; dist < vertexCount; dist++)
                res[dist - 1] = (vertexCount - dist) * 2;
            return res;
        }

        if (a > b)
            swap(a, b);

        int cycleSize = b - a + 1;
        int lineSize = vertexCount - (b - a) + 1;

        if (cycleSize / 2 >= 1)
            res[0] += cycleSize == 2 ? 1 : cycleSize;
        if (lineSize > 2)
            res[0] += lineSize - 2;

        for (int dist = 2; dist < vertexCount; dist++) {
            if (cycleSize / 2 >= dist)
                res[dist - 1] += cycleSize == dist * 2 ? cycleSize / 2 : cycleSize;
            if (lineSize > dist)
                res[dist - 1] += lineSize - dist;

            int cycleDistLimit = min(dist - 1, cycleSize / 2);
            for (int cycleDist : { max(1, dist - (a - 1)), max(1, dist - (vertexCount - b)) }) {
                if (cycleDist <= cycleDistLimit) {
                    res[dist - 1] += 2 * (cycleDistLimit - cycleDist + 1);
                    res[dist - 1] -= cycleDist == 1;
                    res[dist - 1] -= cycleDistLimit * 2 == cycleSize;
                }
            }
        }

        for (long long &value : res)
            value *= 2;

        return res;
    }
};