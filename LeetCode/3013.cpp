struct TwoSet {
    int lSize;
    multiset<int> l, r;
    long long lSum = 0;

    TwoSet(int lSize) : lSize(lSize) {}

    void rebalance() {
        while (l.size() < lSize && !r.empty()) {
            l.insert(*r.begin());
            lSum += *r.begin();
            r.erase(r.begin());
        }
        while (l.size() > lSize) {
            r.insert(*prev(l.end()));
            lSum -= *r.begin();
            l.erase(prev(l.end()));
        }
    }

    void insert(int value) {
        if (l.size() < lSize || value <= *prev(l.end())) {
            l.insert(value);
            lSum += value;
        } else {
            r.insert(value);
        }
        rebalance();
    }

    void erase(int value) {
        if (auto it = l.find(value); it != l.end()) {
            l.erase(it);
            lSum -= value;
        } else {
            r.erase(r.find(value));
        }
        rebalance();
    }
};

class Solution {
public:
    long long minimumCost(vector<int> &a, int partCount, int dist) {
        TwoSet values(partCount - 1);

        for (int i = 1; i <= 1 + dist; i++)
            values.insert(a[i]);
        long long res = a[0] + values.lSum;

        for (int l = 1, r = 2 + dist; r < a.size(); l++, r++) {
            values.erase(a[l]);
            values.insert(a[r]);
            res = min(res, a[0] + values.lSum);
        }

        return res;
    }
};