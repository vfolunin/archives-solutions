struct SegmentTree {
    struct Data {
        vector<int> values;
        vector<long long> prefixSum;

        Data() {}

        Data(int value) : values(1, value), prefixSum(1, value) {}

        Data(Data &l, Data &r) {
            merge(l.values.begin(), l.values.end(), r.values.begin(), r.values.end(), back_inserter(values));
            prefixSum = { values.begin(), values.end() };
            partial_sum(prefixSum.begin(), prefixSum.end(), prefixSum.begin());
        }

        int getLessCount(int value) {
            return lower_bound(values.begin(), values.end(), value) - values.begin();
        }

        tuple<int, int, long long, long long> getCountsAndSums(int value) {
            int lessCount = getLessCount(value);
            int greaterCount = values.size() - lessCount;
            long long lessSum = lessCount ? prefixSum[lessCount - 1] : 0;
            long long greaterSum = prefixSum.back() - lessSum;
            return { lessCount, greaterCount, lessSum, greaterSum };
        }
    };

    int size;
    vector<Data> t;

    void build(int v, int vl, int vr, const vector<int> &a) {
        if (vl == vr) {
            t[v] = Data(a[vl]);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, a);
        build(2 * v + 2, vm + 1, vr, a);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    int queryLessCount(int v, int vl, int vr, int l, int r, int value) {
        if (vr < l || r < vl)
            return 0;
        if (l <= vl && vr <= r)
            return t[v].getLessCount(value);
        int vm = vl + (vr - vl) / 2;
        int lLessCount = queryLessCount(2 * v + 1, vl, vm, l, r, value);
        int rLessCount = queryLessCount(2 * v + 2, vm + 1, vr, l, r, value);
        return lLessCount + rLessCount;
    }

    tuple<int, int, long long, long long> queryCountsAndSums(int v, int vl, int vr, int l, int r, int value) {
        if (vr < l || r < vl)
            return { 0, 0, 0, 0 };
        if (l <= vl && vr <= r)
            return t[v].getCountsAndSums(value);
        int vm = vl + (vr - vl) / 2;
        auto [lLessCount, lGreaterCount, lLessSum, lGreaterSum] = queryCountsAndSums(2 * v + 1, vl, vm, l, r, value);
        auto [rLessCount, rGreaterCount, rLessSum, rGreaterSum] = queryCountsAndSums(2 * v + 2, vm + 1, vr, l, r, value);
        return { lLessCount + rLessCount, lGreaterCount + rGreaterCount, lLessSum + rLessSum, lGreaterSum + rGreaterSum };
    }

    SegmentTree(vector<int> &a) : size(a.size()) {
        t.resize(4 * size);
        build(0, 0, size - 1, a);
    }

    long long query(int l, int r) {
        int lValue = -1, rValue = 1e9 + 1;
        while (lValue + 1 < rValue) {
            int value = lValue + (rValue - lValue) / 2;
            if (queryLessCount(0, 0, size - 1, l, r, value) * 2 <= r - l + 1)
                lValue = value;
            else
                rValue = value;
        }
        long long median = lValue;

        auto [lessCount, greaterCount, lessSum, greaterSum] = queryCountsAndSums(0, 0, size - 1, l, r, lValue);
        return lessCount * median - lessSum + greaterSum - greaterCount * median;
    }
};

class Solution {
public:
    vector<long long> minOperations(vector<int> &a, int delta, vector<vector<int>> &queries) {
        vector<int> change(a.size(), a.size()), stack;
        for (int i = 0; i < a.size(); i++) {
            while (!stack.empty() && a[stack.back()] % delta != a[i] % delta) {
                change[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }
        
        SegmentTree segmentTree(a);

        vector<long long> res(queries.size(), -1);
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1];
            if (r < change[l])
                res[i] = segmentTree.query(l, r) / delta;
        }
        return res;
    }
};