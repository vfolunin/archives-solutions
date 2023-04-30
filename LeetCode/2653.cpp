class KthFinder {
    int k;
    multiset<int> l, r;
    
    void rebalance() {
        while (l.size() < k && !r.empty()) {
            l.insert(*r.begin());
            r.erase(r.begin());
        }
        while (l.size() > k) {
            r.insert(*--l.end());
            l.erase(--l.end());
        }
    }
    
public:
    KthFinder(int k) : k(k) {}

    void insert(int n) {
        if (l.empty() || n <= *prev(l.end()))
            l.insert(n);
        else
            r.insert(n);
        rebalance();
    }
    
    void erase(int n) {
        if (n <= *prev(l.end()))
            l.erase(l.find(n));
        else
            r.erase(r.find(n));
        rebalance();
    }
    
    int getKth() {
        return *prev(l.end());
    }
};

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int> &a, int windowSize, int k) {
        KthFinder kthFinder(k);

        for (int i = 0; i < windowSize; i++)
            kthFinder.insert(a[i]);
        vector<int> res = { min(0, kthFinder.getKth()) };

        for (int i = windowSize; i < a.size(); i++) {
            kthFinder.erase(a[i - windowSize]);
            kthFinder.insert(a[i]);
            res.push_back(min(0, kthFinder.getKth()));
        }

        return res;
    }
};