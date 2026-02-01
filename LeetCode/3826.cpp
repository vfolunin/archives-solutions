class Solution {
    long long getSum(vector<long long> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }

    void rec(vector<vector<long long>> &res, int parts, int sizeL, int sizeR, int bestPrevSizeL, int bestPrevSizeR, vector<long long> &p) {
        if (sizeL > sizeR)
            return;

        int size = sizeL + (sizeR - sizeL) / 2;
        int bestPrevSize = bestPrevSizeL;

        for (int prevSize = bestPrevSizeL; prevSize <= bestPrevSizeR && prevSize < size; prevSize++) {
            long long partSum = getSum(p, prevSize, size - 1);
            long long partPrice = partSum * (partSum + 1) / 2;

            if (res[parts][size] > res[parts - 1][prevSize] + partPrice) {
                res[parts][size] = res[parts - 1][prevSize] + partPrice;
                bestPrevSize = prevSize;
            }
        }

        rec(res, parts, sizeL, size - 1, bestPrevSizeL, bestPrevSize, p);
        rec(res, parts, size + 1, sizeR, bestPrevSize, bestPrevSizeR, p);
    }

public:
    long long minPartitionScore(vector<int> &a, int partCount) {
        vector<long long> p(a.size());
        partial_sum(a.begin(), a.end(), p.begin());

        vector<vector<long long>> res(partCount + 1, vector<long long>(a.size() + 1, 1e18));
        res[0][0] = 0;

        for (int parts = 1; parts <= partCount; parts++)
            rec(res, parts, 0, a.size(), 0, a.size(), p);

        return res[partCount][a.size()];
    }
};