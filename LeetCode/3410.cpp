struct SegmentTree {
    struct Data {
        long long sum, maxPrefixSum, maxSuffixSum, maxSum;

        Data() {}

        Data(int value) : sum(value), maxPrefixSum(value), maxSuffixSum(value), maxSum(value) {}

        Data(Data &l, Data &r) {
            sum = l.sum + r.sum;
            maxPrefixSum = max(l.maxPrefixSum, l.sum + r.maxPrefixSum);
            maxSuffixSum = max(l.maxSuffixSum + r.sum, r.maxSuffixSum);
            maxSum = max({ l.maxSum, r.maxSum, l.maxSuffixSum + r.maxPrefixSum });
        }
    };

    int size;
    vector<Data> t;

    void build(int v, int vl, int vr, vector<int> &a) {
        if (vl == vr) {
            t[v] = Data(a[vl]);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, a);
        build(2 * v + 2, vm + 1, vr, a);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    void modify(int v, int vl, int vr, int index, int value) {
        if (vl == vr) {
            t[v] = Data(value);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        if (index <= vm)
            modify(2 * v + 1, vl, vm, index, value);
        else
            modify(2 * v + 2, vm + 1, vr, index, value);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(vector<int> &a) : size(a.size()), t(4 * a.size()) {
        build(0, 0, size - 1, a);
    }

    long long getMaxSum() {
        return t[0].maxSum;
    }

    void setValue(int index, int value) {
        modify(0, 0, size - 1, index, value);
    }
};

class Solution {
public:
    long long maxSubarraySum(vector<int> &a) {
        unordered_map<int, vector<int>> pos;
        int negativeValueCount = 0, maxValue = -1e9;
        for (int i = 0; i < a.size(); i++) {
            pos[a[i]].push_back(i);
            negativeValueCount += a[i] < 0;
            maxValue = max(maxValue, a[i]);
        }

        if (negativeValueCount == a.size())
            return maxValue;
        
        SegmentTree segmentTree(a);
        long long res = segmentTree.getMaxSum();

        for (auto &[value, pos] : pos) {
            for (int i : pos)
                segmentTree.setValue(i, 0);

            res = max(res, segmentTree.getMaxSum());

            for (int i : pos)
                segmentTree.setValue(i, value);
        }

        return res;
    }
};