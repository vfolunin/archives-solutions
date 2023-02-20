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
    int kEmptySlots(vector<int> &a, int k) {
        BIT bit(a.size());

        for (int i = 0; i < a.size(); i++) {
            int index = a[i] - 1;
            bit.add(index, 1);

            if (0 <= index - k - 1 && bit.sum(index - k - 1, index - k - 1) && !bit.sum(index - k, index - 1) ||
                index + k + 1 < a.size() && bit.sum(index + k + 1, index + k + 1) && !bit.sum(index + 1, index + k))
                return i + 1;
        }

        return -1;
    }
};