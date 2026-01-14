struct XorBasis {
    vector<int> basis;

    XorBasis(vector<int> &a) : basis(30) {
        for (int value : a) {
            for (int bit = basis.size() - 1; bit >= 0; bit--) {
                if (value & (1 << bit)) {
                    if (!basis[bit]) {
                        basis[bit] = value;
                        break;
                    }
                    value ^= basis[bit];
                }
            }
        }
    }

    int getBestXor(int mask) {
        int res = 0;
        for (int bit = basis.size() - 1; bit >= 0; bit--)
            if (((res ^ basis[bit]) & ~mask) > (res & ~mask))
                res ^= basis[bit];
        return res;
    }
};

class Solution {
public:
    long long maximizeXorAndXor(vector<int> &a) {
        long long res = 0;

        for (int mask = 1; mask < (1 << a.size()); mask++) {
            long long andSum = -1, xorSum = 0;
            for (int bit = 0; bit < a.size(); bit++) {
                if (mask & (1 << bit))
                    andSum &= a[bit];
                else
                    xorSum ^= a[bit];
            }

            vector<int> basisValues;
            for (int bit = 0; bit < a.size(); bit++)
                if (!(mask & (1 << bit)))
                    basisValues.push_back(a[bit] & ~xorSum);
            int bestXor = XorBasis(basisValues).getBestXor(xorSum);

            res = max(res, andSum + bestXor + (xorSum ^ bestXor));
        }

        return res;
    }
};