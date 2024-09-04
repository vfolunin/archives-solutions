long long binPow(long long x, long long p, long long mod) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1, mod) * x % mod;
    long long r = binPow(x, p / 2, mod);
    return r * r % mod;
}

struct MultipliedValue {
    int initValue, factor, power, index;

    double getApproximateValue() const {
        return initValue * pow(factor, power);
    }

    int getExactValue() const {
        static const long long MOD = 1e9 + 7;
        return 1LL * initValue * binPow(factor, power, MOD) % MOD;
    }

    bool operator < (const MultipliedValue &that) const {
        double value = getApproximateValue();
        double thatValue = that.getApproximateValue();
        if (value != thatValue)
            return value < thatValue;
        return index < that.index;
    }
};

class Solution {
public:
    vector<int> getFinalState(vector<int> &a, int opCount, int factor) {
        if (factor == 1)
            return a;
            
        set<MultipliedValue> multipliedValueSet;
        for (int i = 0; i < a.size(); i++)
            multipliedValueSet.insert({ a[i], factor, 0, i });
        
        for ( ; opCount; opCount--) {
            MultipliedValue multipliedValue = *multipliedValueSet.begin();
            multipliedValue.power++;
            if (*prev(multipliedValueSet.end()) < multipliedValue)
                break;
            
            multipliedValueSet.erase(multipliedValueSet.begin());
            multipliedValueSet.insert(multipliedValue);
        }

        vector<MultipliedValue> multipliedValues(multipliedValueSet.begin(), multipliedValueSet.end());
        for (int i = 0; i < multipliedValues.size(); i++)
            multipliedValues[i].power += opCount / multipliedValues.size() + (i < opCount % multipliedValues.size());
        
        vector<int> res(multipliedValues.size());
        for (MultipliedValue &multipliedValue : multipliedValues)
            res[multipliedValue.index] = multipliedValue.getExactValue();
        return res;
    }
};