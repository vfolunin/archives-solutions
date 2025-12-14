struct BIT {
    vector<int> f;

    BIT(int size) : f(size) {}

    int sum(int r) {
        int res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += f[r];
        return res;
    }

    int sum(int l, int r) {
        return sum(r) - (l ? sum(l - 1) : 0);
    }

    void add(int i, int v) {
        for (; i < f.size(); i |= i + 1)
            f[i] += v;
    }

    void set(int i, int v) {
        add(i, v - sum(i, i));
    }
};

class Solution {
public:
    vector<int> minDeletions(string &s, vector<vector<int>> &queries) {
        BIT bit(s.size() - 1);
        for (int i = 0; i + 1 < s.size(); i++)
            bit.set(i, s[i] == s[i + 1]);
        
        vector<int> res;
        for (vector<int> &query : queries) {
            if (query[0] == 1) {
                int i = query[1];
                s[i] = 'A' + 'B' - s[i];
                if (i > 0)
                    bit.set(i - 1, s[i - 1] == s[i]);
                if (i + 1 < s.size())
                    bit.set(i, s[i] == s[i + 1]);
            } else {
                int l = query[1], r = query[2];
                res.push_back(bit.sum(l, r - 1));
            }
        }
        return res;
    }
};