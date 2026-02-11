struct SegmentTree {
    struct Data {
        int minValue = 0, maxValue = 0, delta = 0;
        
        Data() {}

        Data(int value) : minValue(value), maxValue(value) {}

        Data(Data &l, Data &r) : minValue(min(l.minValue, r.minValue)), maxValue(max(l.maxValue, r.maxValue)) {}

        void applyDelta() {
            minValue += delta;
            maxValue += delta;
            delta = 0;
        }

        bool hasZero() {
            return minValue + delta <= 0 && 0 <= maxValue + delta;
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

    void push(int v, int vl, int vr) {
        if (t[v].delta) {
            if (vl < vr) {
                t[2 * v + 1].delta += t[v].delta;
                t[2 * v + 2].delta += t[v].delta;
            }
            t[v].applyDelta();
        }
    }

    void modify(int v, int vl, int vr, int l, int r, int value) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return;
        if (l <= vl && vr <= r) {
            t[v].delta += value;
            push(v, vl, vr);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, l, r, value);
        modify(2 * v + 2, vm + 1, vr, l, r, value);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    int getLastZeroIndex(int v, int vl, int vr) {
        push(v, vl, vr);
        if (!t[v].hasZero())
            return -1;
        if (vl == vr)
            return vl;
        int vm = vl + (vr - vl) / 2;
        if (t[2 * v + 2].hasZero())
            return getLastZeroIndex(2 * v + 2, vm + 1, vr);
        else
            return getLastZeroIndex(2 * v + 1, vl, vm);
    }

    SegmentTree(vector<int> &a) : size(a.size()), t(4 * size) {
        build(0, 0, size - 1, a);
    }

    int getLastZeroIndex() {
        return getLastZeroIndex(0, 0, size - 1);
    }

    void addValue(int l, int r, int value) {
        modify(0, 0, size - 1, l, r, value);
    }
};

class Solution {
    int getSign(int value) {
        return value % 2 ? 1 : -1;
    }

public:
    int longestBalanced(vector<int> &a) {
        unordered_map<int, deque<int>> pos;
        for (int i = 0; i < a.size(); i++)
            pos[a[i]].push_back(i);
        for (auto &[value, pos] : pos)
            pos.push_back(a.size());
        
        vector<int> prefixBalance(a.size());
        for (int i = 0; i < a.size(); i++) {
            if (i)
                prefixBalance[i] = prefixBalance[i - 1];
            if (pos[a[i]][0] == i)
                prefixBalance[i] += getSign(a[i]);
        }

        SegmentTree segmentTree(prefixBalance);
        int res = segmentTree.getLastZeroIndex() + 1;

        for (int i = 0; i < a.size(); i++) {
            segmentTree.addValue(pos[a[i]][0], pos[a[i]][1] - 1, -getSign(a[i]));
            pos[a[i]].pop_front();

            res = max(res, segmentTree.getLastZeroIndex() - i);
        }

        return res;
    }
};