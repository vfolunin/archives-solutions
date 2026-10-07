struct ModInt {
    long long value;
    static const long long mod = 1e9 + 7;

    static long long gcdex(long long a, long long b, long long &x, long long &y) {
        if (!b) {
            x = 1;
            y = 0;
            return a;
        }
        long long x1, y1, d = gcdex(b, a % b, x1, y1);
        x = y1;
        y = x1 - a / b * y1;
        return d;
    }

    ModInt(long long value = 0) : value((value % mod + mod) % mod) {}

    ModInt operator + (const ModInt &that) const {
        return value + that.value;
    }

    ModInt operator - (const ModInt &that) const {
        return value - that.value;
    }

    ModInt operator * (const ModInt &that) const {
        return value * that.value;
    }

    ModInt operator / (const ModInt &that) const {
        long long x, y;
        gcdex(that.value, mod, x, y);
        return value * x;
    }
};

class Solution {
    struct Sums {
        ModInt ll, llr, lr, lrr, rr;

        void update(ModInt l, ModInt r, int sign) {
            ll = ll + l * l * sign;
            llr = llr + l * l * r * sign;
            lr = lr + l * r * sign;
            lrr = lrr + l * r * r * sign;
            rr = rr + r * r * sign;
        }
    };

    ModInt c2(long long n) {
        return n * (n - 1) / 2;
    }

public:
    int subsequencesWithMiddleMode(vector<int> &a) {
        long long lSize = 0, rSize = a.size();
        unordered_map<int, long long> lCount, rCount;
        for (int value : a)
            rCount[value]++;

        Sums sums;
        for (auto &[value, count] : rCount)
            sums.update(0, count, 1);

        ModInt res;
        for (int value : a) {
            sums.update(lCount[value], rCount[value], -1);
            rSize--;
            rCount[value]--;
            sums.update(lCount[value], rCount[value], 1);

            ModInt l = lCount[value], r = rCount[value];
            ModInt lOther = lSize - lCount[value], rOther = rSize - rCount[value];

            Sums otherSums = sums;
            otherSums.update(l, r, -1);

            res = res + c2(lSize) * c2(rSize);
            res = res - c2(lSize - lCount[value]) * c2(rSize - rCount[value]);
            res = res - r * rOther * (otherSums.ll - lOther) / 2;
            res = res - l * lOther * (otherSums.rr - rOther) / 2;
            res = res - l * (rOther * otherSums.lr - otherSums.lrr);
            res = res - r * (lOther * otherSums.lr - otherSums.llr);

            sums.update(lCount[value], rCount[value], -1);
            lSize++;
            lCount[value]++;
            sums.update(lCount[value], rCount[value], 1);
        }

        return res.value;
    }
};