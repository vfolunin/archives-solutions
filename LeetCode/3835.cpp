class SparseTable {
    vector<int> lg;
    vector<vector<int>> stMin, stMax;

public:
    SparseTable(vector<int> &a) {
        lg.resize(a.size() + 1);
        for (int i = 2; i <= a.size(); i++)
            lg[i] = lg[i / 2] + 1;

        stMin.push_back(a);
        stMax.push_back(a);
        for (int level = 1, levelWidth = 2; levelWidth <= a.size(); level++, levelWidth *= 2) {
            stMin.emplace_back();
            stMax.emplace_back();
            for (int i = 0; i + levelWidth <= a.size(); i++) {
                stMin[level].push_back(min(stMin[level - 1][i], stMin[level - 1][i + levelWidth / 2]));
                stMax[level].push_back(max(stMax[level - 1][i], stMax[level - 1][i + levelWidth / 2]));
            }
        }
    }

    int getMin(int l, int r) {
        int level = lg[r - l + 1], levelWidth = 1 << level;
        return min(stMin[level][l], stMin[level][r - levelWidth + 1]);
    }

    int getMax(int l, int r) {
        int level = lg[r - l + 1], levelWidth = 1 << level;
        return max(stMax[level][l], stMax[level][r - levelWidth + 1]);
    }

    int getValue(int l, int r) {
        return getMax(l, r) - getMin(l, r);
    }
};

class Solution {
public:
    long long countSubarrays(vector<int> &a, long long limit) {
        SparseTable sparseTable(a);
        long long res = 0;
        for (int l = 0, r = 0; r < a.size(); r++) {
            while (sparseTable.getValue(l, r) * (r - l + 1LL) > limit)
                l++;
            res += r - l + 1;
        }
        return res;
    }
};