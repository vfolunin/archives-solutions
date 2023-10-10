struct SegmentTree {
    struct Data {
        int value = -1e9, pointIndex = -1;

        Data() {}

        Data(int value, int pointIndex) : value(value), pointIndex(pointIndex) {}

        Data(Data &l, Data &r) {
            *this = l.value > r.value || l.value == r.value && l.pointIndex < r.pointIndex ? l : r;
        }
    };
    int size;
    vector<Data> t;

    Data query(int v, int vl, int vr, int l, int r) {
        if (vr < l || r < vl)
            return Data();
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        Data ql = query(2 * v + 1, vl, vm, l, r);
        Data qr = query(2 * v + 2, vm + 1, vr, l, r);
        return Data(ql, qr);
    }

    void modify(int v, int vl, int vr, int index, int value, int pointIndex) {
        if (vr < index || index < vl)
            return;
        if (vl == vr) {
            t[v] = Data(value, pointIndex);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, index, value, pointIndex);
        modify(2 * v + 2, vm + 1, vr, index, value, pointIndex);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(int size) : size(size), t(4 * size) {}

    int getPointIndex(int l, int r) {
        return query(0, 0, size - 1, l, r).pointIndex;
    }

    void insert(int x, int value, int pointIndex) {
        modify(0, 0, size - 1, x, value, pointIndex);
    }
};

class Solution {
public:
    vector<int> beautifulPair(vector<int> &x, vector<int> &y) {
        vector<int> pointIndexes(x.size());
        iota(pointIndexes.begin(), pointIndexes.end(), 0);
        stable_sort(pointIndexes.begin(), pointIndexes.end(), [&](int l, int r) {
            if (y[l] != y[r])
                return y[l] < y[r];
            return x[l] < x[r];
        });

        SegmentTree l(x.size() + 1), r(x.size() + 1);

        int bestDist = 2e9, bestI, bestJ;
        for (int i : pointIndexes) {
            int dist = 2e9, j = -1;

            int lj = l.getPointIndex(0, x[i]);
            if (lj != -1) {
                int lDist = abs(x[i] - x[lj]) + abs(y[i] - y[lj]);
                if (dist > lDist) {
                    dist = lDist;
                    j = lj;
                }
            }

            int rj = r.getPointIndex(x[i], x.size());
            if (rj != -1) {
                int rDist = abs(x[i] - x[rj]) + abs(y[i] - y[rj]);
                if (dist > rDist || dist == rDist && j > rj) {
                    dist = rDist;
                    j = rj;
                }
            }

            if (j != -1) {
                int curI = i, curJ = j;
                if (curI > curJ)
                    swap(curI, curJ);

                if (bestDist > dist || bestDist == dist && bestI > curI ||
                    bestDist == dist && bestI == curI && bestJ > curJ) {
                    bestDist = dist;
                    bestI = curI;
                    bestJ = curJ;
                }
            }

            l.insert(x[i], y[i] + x[i], i);
            r.insert(x[i], y[i] - x[i], i);
        }

        return { bestI, bestJ };
    }
};