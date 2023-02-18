struct SegmentTree {
    int size;
    vector<long long> t;
    vector<int> tFlip;
    
    void build(int v, int vl, int vr, vector<int> &a) {
        if (vl == vr) {
            t[v] = a[vl];
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, a);
        build(2 * v + 2, vm + 1, vr, a);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
    
    void push(int v, int vl, int vr) {
        if (tFlip[v]) {
            t[v] = (vr - vl + 1) - t[v];
            if (vl < vr) {
                tFlip[2 * v + 1] ^= 1;
                tFlip[2 * v + 2] ^= 1;
            }
            tFlip[v] = 0;
        }
    }

    long long query(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return 0;
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        long long ql = query(2 * v + 1, vl, vm, l, r);
        long long qr = query(2 * v + 2, vm + 1, vr, l, r);
        return ql + qr;
    }

    void modify(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return;
        if (l <= vl && vr <= r) {
            tFlip[v] ^= 1;
            push(v, vl, vr);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, l, r);
        modify(2 * v + 2, vm + 1, vr, l, r);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    SegmentTree(vector<int> &a) :
        size(a.size()), t(4 * a.size()), tFlip(4 * a.size()) {
        build(0, 0, size - 1, a);
    }

    long long getSum(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }

    void flip(int l, int r) {
        modify(0, 0, size - 1, l, r);
    }
};

class Solution {
public:
    vector<long long> handleQuery(vector<int> &a, vector<int> &b, vector<vector<int>> &queries) {
        SegmentTree st(a);
        long long sum = accumulate(b.begin(), b.end(), 0LL);
        
        vector<long long> res;        
        for (vector<int> &query : queries) {
            if (query[0] == 1)
                st.flip(query[1], query[2]);
            else if (query[0] == 2)
                sum += query[1] * st.getSum(0, a.size() - 1);
            else
                res.push_back(sum);
        }        
        return res;
    }
};