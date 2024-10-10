class PrefixSum {
    vector<long long> p;

public:
    PrefixSum(vector<int> &a) : p(a.begin(), a.end()) {
        partial_sum(p.begin(), p.end(), p.begin());
    }

    long long getSum(int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }
};

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
                st[level].push_back(gcd(st[level - 1][i], st[level - 1][i + levelWidth / 2]));
        }
    }

    int getGcd(int l, int r) {
        int level = lg[r - l + 1], levelWidth = 1 << level;
        return gcd(st[level][l], st[level][r - levelWidth + 1]);
    }
};

class Solution {
    int getTo(SparseTable &sparseTable, int from, int l, int r) {
        int gcdValue = sparseTable.getGcd(from, l);
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (sparseTable.getGcd(from, m) == gcdValue)
                l = m;
            else
                r = m;
        }
        return l;
    }

public:
    long long maxGcdSum(vector<int> &a, int minWidth) {
        PrefixSum prefixSum(a);
        SparseTable sparseTable(a);
        long long res = 0;

        for (int from = 0; from + minWidth <= a.size(); from++) {
            for (int to = from + minWidth - 1; to < a.size(); to++) {
                to = getTo(sparseTable, from, to, a.size());
                long long curSum = prefixSum.getSum(from, to);
                int curGcd = sparseTable.getGcd(from, to);
                res = max(res, curSum * curGcd);
            }
        }

        return res;
    }
};