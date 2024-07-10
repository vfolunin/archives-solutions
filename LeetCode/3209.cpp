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
public:
    long long countSubarrays(vector<int> &a, int targetAnd) {
        SparseTable sparseTable(a);
        long long res = 0;

        for (int l = 0, r1 = 0, r2 = 0; l < a.size(); l++) {
            while (r1 < l || r1 < a.size() && sparseTable.getAnd(l, r1) > targetAnd)
                r1++;
            while (r2 < r1 || r2 < a.size() && sparseTable.getAnd(l, r2) >= targetAnd)
                r2++;
            res += r2 - r1;
        }

        return res;
    }
};