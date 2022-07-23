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
};

class Solution {
public:
    vector<int> countSmaller(vector<int> &a) {
        BIT bit(2e4 + 1);
        vector<int> res(a.size());
        
        for (int i = a.size() - 1; i >= 0; i--) {
            res[i] = bit.sum(a[i] + 1e4 - 1);
            bit.add(a[i] + 1e4, 1);
        }
        
        return res;
    }
};