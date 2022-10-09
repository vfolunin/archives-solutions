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
            for (int i = 0; i + (1 << level) <= a.size(); i++)
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
    int closestToTarget(vector<int> &a, int target) {
        SparseTable st(a);
        int res = 1e9;
        
        for (int from = 0; from < a.size(); from++) {
            int l = from, r = a.size() - 1;
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (st.getAnd(from, m) > target)
                    l = m;
                else
                    r = m;
            }
            res = min(res, abs(st.getAnd(from, l) - target));
            res = min(res, abs(st.getAnd(from, r) - target));
        }
        
        return res;
    }
};