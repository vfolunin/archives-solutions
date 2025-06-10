class SparseTable {
    vector<int> lg;
    vector<vector<int>> tMin, tMax;

public:
    SparseTable(vector<int> &a) {
        lg.resize(a.size() + 1);
        for (int i = 2; i <= a.size(); i++)
            lg[i] = lg[i / 2] + 1;

        tMin.push_back(a);
        tMax.push_back(a);
        for (int level = 1, levelWidth = 2; levelWidth <= a.size(); level++, levelWidth *= 2) {
            tMin.emplace_back();
            tMax.emplace_back();
            for (int i = 0; i + levelWidth <= a.size(); i++) {
                tMin[level].push_back(min(tMin[level - 1][i], tMin[level - 1][i + levelWidth / 2]));
                tMax[level].push_back(max(tMax[level - 1][i], tMax[level - 1][i + levelWidth / 2]));
            }
        }
    }

    int getDiff(int l, int r) {
        int level = lg[r - l + 1], levelWidth = 1 << level;
        int minValue = min(tMin[level][l], tMin[level][r - levelWidth + 1]);
        int maxValue = max(tMax[level][l], tMax[level][r - levelWidth + 1]);
        return maxValue - minValue;
    }
};

class Solution {
    static const long long MOD = 1e9 + 7;

    long long getSum(vector<long long> &p, int l, int r) {
        long long res = p[r];
        if (l)
            res = (res - p[l - 1] + MOD) % MOD;
        return res;
    }

public:
    int countPartitions(vector<int> &a, int limit) {
        SparseTable sparseTable(a);

        vector<long long> pWays(a.size() + 1);
        pWays[0] = 1;

        for (int i = 1; i <= a.size(); i++) {
            int l = 0, r = i;
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (sparseTable.getDiff(m - 1, i - 1) <= limit)
                    r = m;
                else
                    l = m;
            }

            pWays[i] = (getSum(pWays, r - 1, i - 1) + pWays[i - 1]) % MOD;
        }

        return getSum(pWays, a.size(), a.size());
    }
};