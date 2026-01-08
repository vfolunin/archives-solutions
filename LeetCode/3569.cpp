struct SegmentTree {
    struct Data {
        int maxValue = -1e9, add = 0;

        Data() {}

        Data(int value) : maxValue(value) {}

        Data(Data &l, Data &r) : maxValue(max(l.maxValue, r.maxValue)) {}

        bool hasDelta() {
            return add;
        }

        int getDelta() {
            return add;
        }

        void addDelta(int delta) {
            add += delta;
        }

        void applyDelta(int vl, int vr) {
            maxValue += add;
            add = 0;
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
        if (t[v].hasDelta()) {
            if (vl != vr) {
                int vm = vl + (vr - vl) / 2;
                t[2 * v + 1].addDelta(t[v].getDelta());
                t[2 * v + 2].addDelta(t[v].getDelta());
            }
            t[v].applyDelta(vl, vr);
        }
    }

    void modify(int v, int vl, int vr, int l, int r, int delta) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return;
        if (l <= vl && vr <= r) {
            t[v].addDelta(delta);
            push(v, vl, vr);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, l, r, delta);
        modify(2 * v + 2, vm + 1, vr, l, r, delta);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(vector<int> &a) : size(a.size()), t(4 * a.size()) {
        build(0, 0, size - 1, a);
    }

    int getMaxValue() {
        return t[0].maxValue;
    }

    void add(int l, int r, int delta) {
        modify(0, 0, size - 1, l, r, delta);
    }
};

class Solution {
    vector<int> getIsPrime(int n) {
        vector<int> isPrime(n + 1, 1);
        isPrime[0] = isPrime[1] = 0;
        for (int i = 2; i < isPrime.size(); i++)
            if (isPrime[i])
                for (long long j = 1LL * i * i; j < isPrime.size(); j += i)
                    isPrime[j] = 0;
        return isPrime;
    }

public:
    vector<int> maximumCount(vector<int> &a, vector<vector<int>> &queries) {
        static vector<int> isPrime = getIsPrime(1e5);

        unordered_map<int, set<int>> pos;
        for (int i = 0; i < a.size(); i++)
            if (isPrime[a[i]])
                pos[a[i]].insert(i);
        
        vector<int> segments(a.size() + 1);
        for (auto &[_, pos] : pos) {
            if (pos.size() >= 2) {
                segments[*pos.begin()] += 1;
                segments[*prev(pos.end()) + 1] -= 1;
            }
        }
        partial_sum(segments.begin(), segments.end(), segments.begin());

        SegmentTree segmentTree(segments);
        vector<int> res(queries.size());

        for (int i = 0; i < res.size(); i++) {
            int index = queries[i][0], prevValue = a[index], value = queries[i][1];
            a[index] = value;

            if (isPrime[prevValue]) {
                if (pos[prevValue].size() >= 2) {
                    set<int> &p = pos[prevValue];
                    int l = *p.begin(), r = *prev(p.end());
                    if (index == l || index == r) {
                        segmentTree.add(l, r, -1);
                        p.erase(index);
                        if (p.size() >= 2)
                            segmentTree.add(*p.begin(), *prev(p.end()), 1);
                    } else {
                        p.erase(index); 
                    }
                } else {
                    pos.erase(prevValue);
                }
            }

            if (isPrime[value]) {
                if (pos.count(value)) {
                    set<int> &p = pos[value];
                    int l = *p.begin(), r = *prev(p.end());
                    if (index < l || r < index) {
                        if (p.size() >= 2)
                            segmentTree.add(*p.begin(), *prev(p.end()), -1);
                        p.insert(index);
                        segmentTree.add(*p.begin(), *prev(p.end()), 1);
                    } else {
                        p.insert(index);
                    }
                } else {
                    pos[value].insert(index);
                }
            }

            res[i] = pos.size() + segmentTree.getMaxValue();
        }

        return res;
    }
};