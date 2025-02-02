class Solution {
public:
    long long minCost(int size, vector<vector<int>> &price) {
        vector cost(size + 1, vector(3, vector<long long>(3, 1e18)));
        for (int a = 0; a < 3; a++)
            for (int b = 0; b < 3; b++)
                if (a != b)
                    cost[0][a][b] = 0;
        
        for (int ai = size / 2 - 1, bi = size / 2, curSize = 2, nextSize = 0; curSize <= size; ai--, bi++, curSize += 2, nextSize += 2) {
            for (int a = 0; a < 3; a++) {
                for (int b = 0; b < 3; b++) {
                    if (a == b)
                        continue;
                    for (int nextA = 0; nextA < 3; nextA++) {
                        if (a == nextA)
                            continue;    
                        for (int nextB = 0; nextB < 3; nextB++) {
                            if (b == nextB || nextA == nextB)
                                continue;
                            cost[curSize][a][b] = min(cost[curSize][a][b], price[ai][a] + cost[nextSize][nextA][nextB] + price[bi][b]);
                        }
                    }
                }
            }
        }

        long long res = 1e18;
        for (int a = 0; a < 3; a++)
            for (int b = 0; b < 3; b++)
                res = min(res, cost[size][a][b]);
        return res;
    }
};