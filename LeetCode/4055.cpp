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
    long long rec(vector<int> &values, int minValue, int maxValue) {
        if (minValue == maxValue || values.size() < 2)
            return 0;

        int midValue = minValue + (maxValue - minValue) / 2;
        vector<int> smallValues, largeValues;
        for (int value : values) {
            if (value <= midValue)
                smallValues.push_back(value);
            else
                largeValues.push_back(value);
        }

        long long res = rec(smallValues, minValue, midValue) + rec(largeValues, midValue + 1, maxValue);

        BIT bit(values.size());
        vector<int> smallValueStack, largeValueStack;

        for (int i = 0; i < values.size(); i++) {
            if (values[i] <= midValue) {
                while (!smallValueStack.empty() && values[smallValueStack.back()] < values[i]) {
                    bit.add(smallValueStack.back(), -1);
                    smallValueStack.pop_back();
                }
                bit.add(i, 1);
                smallValueStack.push_back(i);
            } else {
                while (!largeValueStack.empty() && values[largeValueStack.back()] >= values[i])
                    largeValueStack.pop_back();

                res += smallValueStack.size() - (largeValueStack.empty() ? 0 : bit.sum(largeValueStack.back()));
                largeValueStack.push_back(i);
            }
        }

        return res;
    }

public:
    long long shadowPairs(vector<int> &values) {
        auto [minIt, maxIt] = minmax_element(values.begin(), values.end());
        return rec(values, *minIt, *maxIt);
    }
};