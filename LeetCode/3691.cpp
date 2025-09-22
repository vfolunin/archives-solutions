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
    long long maxTotalValue(vector<int> &a, int opCount) {
        SparseTable sparseTable(a);
        set<tuple<int, int, int>> values;
        for (int l = 0; l < a.size(); l++)
            values.insert({ sparseTable.getValue(l, a.size() - 1), l, a.size() - 1 });
        
        long long res = 0;
        for (int i = 0; i < opCount; i++) {
            auto [value, l, r] = *prev(values.end());
            values.erase(prev(values.end()));

            res += value;
            if (l < r)
                values.insert({ sparseTable.getValue(l, r - 1), l, r - 1 });
        }
        return res;
    }
};