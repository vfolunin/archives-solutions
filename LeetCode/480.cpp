class MedianFinder {
    multiset<int> l, r;
    
    void rebalance() {
        while (l.size() < r.size()) {
            l.insert(*r.begin());
            r.erase(r.begin());
        }
        while (r.size() + 1 < l.size()) {
            r.insert(*--l.end());
            l.erase(--l.end());
        }
    }
    
public:
    void insert(int n) {
        if (l.empty() || n <= *--l.end())
            l.insert(n);
        else
            r.insert(n);
        rebalance();
    }
    
    void erase(int n) {
        if (n <= *--l.end())
            l.erase(l.find(n));
        else
            r.erase(r.find(n));
        rebalance();
    }
    
    double getMedian() {
        if ((l.size() + r.size()) % 2)
            return *--l.end();
        return ((double)*--l.end() + *r.begin()) / 2;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> a, int k) {
        MedianFinder finder;
        for (int i = 0; i < k; i++)
            finder.insert(a[i]);
        
        vector<double> res = { finder.getMedian() };
        
        for (int i = k; i < a.size(); i++) {
            finder.erase(a[i - k]);
            finder.insert(a[i]);
            res.push_back(finder.getMedian());
        }
        
        return res;
    }
};