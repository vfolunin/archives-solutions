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
                st[level].push_back(gcd(st[level - 1][i], st[level - 1][i + levelWidth / 2]));
        }
    }

    int getGcd(int l, int r) {
        int level = lg[r - l + 1], levelWidth = 1 << level;
        return gcd(st[level][l], st[level][r - levelWidth + 1]);
    }
};

class Solution {
    bool can(SparseTable &sparseTable, int opLimit, int width) {
        for (int l = 0, r = width - 1; r < sparseTable.st[0].size(); ) {
            if (sparseTable.getGcd(l, r) == 1) {
                l++;
                r++;
            } else {
                opLimit--;
                l = r + 1;
                r = l + width - 1;
            }
        }
        return opLimit >= 0;
    }

public:
    int minStable(vector<int> &a, int opLimit) {
        SparseTable sparseTable(a);

        int l = 0, r = 1;
        while (!can(sparseTable, opLimit, r))
            r *= 2;
        
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(sparseTable, opLimit, m))
                r = m;
            else
                l = m;
        }

        return l;
    }
};