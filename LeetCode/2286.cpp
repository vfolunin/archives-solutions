struct SegmentTree {
    struct Data {
        long long sum;
        int maxValue;
        
        Data() {}
        
        Data(int value) :
            sum(value), maxValue(value) {}
        
        Data(const Data &l, const Data &r) :
            sum(l.sum + r.sum), maxValue(max(l.maxValue, r.maxValue)) {}
    };
    
    vector<Data> t;
    int size;
    
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

    Data query(int v, int vl, int vr, int l, int r) {
        if (vr < l || r < vl)
            return 0;
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        Data ql = query(2 * v + 1, vl, vm, l, r);
        Data qr = query(2 * v + 2, vm + 1, vr, l, r);
        return Data(ql, qr);
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
    
    long long getSum(int r) {
        return query(0, 0, size - 1, 0, r).sum;
    }

    int getMaxValue(int r) {
        return query(0, 0, size - 1, 0, r).maxValue;
    }

    void changeValue(int index, int value) {
        modify(0, 0, size - 1, index, value);
    }
};

class BookMyShow {
    int h, w;
    vector<int> seatCount;
    SegmentTree segmentTree;
    
    void book(int y, int count) {
        seatCount[y] -= count;
        segmentTree.changeValue(y, seatCount[y]);
    }
        
public:
    BookMyShow(int h, int w) :
        h(h), w(w), seatCount(h, w), segmentTree(seatCount) {}
    
    vector<int> gather(int k, int maxY) {
        if (segmentTree.getMaxValue(maxY) < k)
            return {};
        
        int l = -1, r = maxY;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (segmentTree.getMaxValue(m) < k)
                l = m;
            else
                r = m;
        }
    
        vector<int> res = { r, w - seatCount[r] };
        book(r, k);
        return res;
    }
    
    bool scatter(int k, int maxY) {
        if (segmentTree.getSum(maxY) < k)
            return 0;
        
        for (int y = 0; k; y++) {
            int count = min(k, seatCount[y]);
            if (count) {
                book(y, count);
                k -= count;
            }
        }
        return 1;
    }
};