class MedianFinder {
    multiset<int> l, r;
    long long lSum = 0, rSum = 0;

    void rebalance() {
        while (l.size() + 1 < r.size()) {
            l.insert(*r.begin());
            lSum += *r.begin();
            rSum -= *r.begin();
            r.erase(r.begin());
        }
        while (r.size() < l.size()) {
            r.insert(*--l.end());
            rSum += *--l.end();
            lSum -= *--l.end();
            l.erase(--l.end());
        }
    }

public:
    void insert(int value) {
        if (r.empty() || value >= *r.begin()) {
            r.insert(value);
            rSum += value;
        } else {
            l.insert(value);
            lSum += value;
        }
        rebalance();
    }

    void erase(int value) {
        if (auto it = l.find(value); it != l.end()) {
            l.erase(it);
            lSum -= value;
        } else {
            r.erase(r.find(value));
            rSum -= value;
        }
        rebalance();
    }

    long long getCost() {
        return *r.begin() * l.size() - lSum + rSum - *r.begin() * r.size();
    }
};

class Solution {
public:
    long long minOperations(vector<int> &a, int windowSize) {
        MedianFinder medianFinder;
        for (int i = 0; i < windowSize; i++)
            medianFinder.insert(a[i]);
        long long res = medianFinder.getCost();

        for (int i = windowSize; i < a.size(); i++) {
            medianFinder.insert(a[i]);
            medianFinder.erase(a[i - windowSize]);
            res = min(res, medianFinder.getCost());
        }

        return res;
    }
};