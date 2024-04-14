struct SparseTable {
    vector<int> lg;
    vector<vector<int>> st;

    SparseTable(vector<int> &a) {
        lg.resize(a.size() + 1);
        for (int i = 2; i <= a.size(); i++)
            lg[i] = lg[i / 2] + 1;

        st.push_back(a);
        for (int level = 1, levelWidth = 2; levelWidth <= a.size(); level++, levelWidth *= 2) {
            st.emplace_back();
            for (int i = 0; i + levelWidth <= a.size(); i++)
                st[level].push_back(st[level - 1][i] | st[level - 1][i + levelWidth / 2]);
        }
    }

    int getOr(int l, int r) {
        int level = lg[r - l + 1], levelWidth = 1 << level;
        return st[level][l] | st[level][r - levelWidth + 1];
    }
};

class Solution {
    bool can(SparseTable &sparseTable, int threshold, int size) {
        for (int l = 0, r = size - 1; r < sparseTable.st[0].size(); l++, r++)
            if (sparseTable.getOr(l, r) >= threshold)
                return 1;
        return 0;
    }

public:
    int minimumSubarrayLength(vector<int> &a, int threshold) {
        SparseTable sparseTable(a);

        int l = 0, r = a.size() + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(sparseTable, threshold, m))
                r = m;
            else
                l = m;
        }

        return r <= a.size() ? r : -1;
    }
};