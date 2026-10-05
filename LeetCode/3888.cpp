class Solution {
public:
    long long minOperations(vector<vector<int>> &a, int size) {
        int height = a.size(), width = a[0].size();

        long long targetValue = -1e18, borderValue = -1e18;
        for (int y = 0; y < height; y++)
            for (int x = 0; x < width; x++)
                targetValue = max<long long>(targetValue, a[y][x]);

        int pHeight = height + 1, pWidth = width + 1;
        vector pMul(pHeight, vector<long long>(pWidth));
        vector pAdd(pHeight, vector<long long>(pWidth));
        long long mulSum = 0, addSum = 0;

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (y) {
                    pMul[y][x] += pMul[y - 1][x];
                    pAdd[y][x] += pAdd[y - 1][x];
                }
                if (x) {
                    pMul[y][x] += pMul[y][x - 1];
                    pAdd[y][x] += pAdd[y][x - 1];
                }
                if (y && x) {
                    pMul[y][x] -= pMul[y - 1][x - 1];
                    pAdd[y][x] -= pAdd[y - 1][x - 1];
                }

                long long mul = 1 - pMul[y][x];
                long long add = -a[y][x] - pAdd[y][x];

                if (y + size <= height && x + size <= width) {
                    if (mul == 0 && add < 0)
                        return -1;
                    if (mul == 1)
                        targetValue = max(targetValue, -add);

                    mulSum += mul;
                    addSum += add;

                    pMul[y][x] += mul;
                    pAdd[y][x] += add;
                    pMul[y][x + size] -= mul;
                    pAdd[y][x + size] -= add;
                    pMul[y + size][x] -= mul;
                    pAdd[y + size][x] -= add;
                    pMul[y + size][x + size] += mul;
                    pAdd[y + size][x + size] += add;
                } else {
                    if (mul == 0) {
                        if (add != 0)
                            return -1;
                    } else {
                        if (borderValue != -1e18 && borderValue != -add)
                            return -1;
                        borderValue = -add;
                    }
                }
            }
        }

        if (borderValue != -1e18) {
            if (targetValue > borderValue)
                return -1;
            targetValue = borderValue;
        }

        return mulSum * targetValue + addSum;
    }
};