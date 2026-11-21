class SparseTable {
    vector<int> lg;
    vector<vector<int>> st;

public:
    SparseTable(vector<int> &a) {
        lg.resize(a.size() + 1);
        for (int i = 2; i <= a.size(); i++)
            lg[i] = lg[i / 2] + 1;

        st.push_back(a);
        for (int level = 1, levelWidth = 2; levelWidth <= a.size(); level++, levelWidth *= 2) {
            st.emplace_back();
            for (int i = 0; i + levelWidth <= a.size(); i++)
                st[level].push_back(st[level - 1][i] & st[level - 1][i + levelWidth / 2]);
        }
    }

    int getAnd(int l, int r) {
        int level = lg[r - l + 1], levelWidth = 1 << level;
        return st[level][l] & st[level][r - levelWidth + 1];
    }
};

class Solution {
    int ones(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }

public:
    int minSetBits(vector<int> &a, int width) {
        SparseTable sparseTable(a);
        vector<int> hasSubmask(1 << 17);
        for (int l = 0, r = width - 1; r < a.size(); l++, r++) {
            int mask = sparseTable.getAnd(l, r);
            if (!mask)
                return -1;
            hasSubmask[mask] = 1;
        }

        for (int mask = 0; mask < hasSubmask.size(); mask++)
            for (int bit = 0; bit < 17; bit++)
                if (mask & (1 << bit))
                    hasSubmask[mask] |= hasSubmask[mask ^ (1 << bit)];

        int res = 1e9;
        for (int mask = 0; mask < hasSubmask.size(); mask++)
            if (!hasSubmask[(hasSubmask.size() - 1) ^ mask])
                res = min(res, ones(mask));
        return res;
    }
};