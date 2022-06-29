class NumArray {
    vector<int> f;

public:
    NumArray(vector<int> &a) : f(a.size()) {
        for (int i = 0; i < a.size(); i++)
            update(i, a[i]);
    }
    
    void update(int i, int value) {
        value -= sumRange(i, i);
        for (; i < f.size(); i |= i + 1)
            f[i] += value;
    }
    
    int sumRange(int r) {
        int res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += f[r];
        return res;
    }
    
    int sumRange(int l, int r) {
        return sumRange(r) - (l ? sumRange(l - 1) : 0);
    }
};