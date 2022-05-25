class MedianFinder {
    multiset<int> l, r;
    
public:    
    void addNum(int n) {
        if (l.empty() || n <= *--l.end())
            l.insert(n);
        else
            r.insert(n);
        
        while (l.size() < r.size()) {
            l.insert(*r.begin());
            r.erase(r.begin());
        }
        while (r.size() + 1 < l.size()) {
            r.insert(*--l.end());
            l.erase(--l.end());
        }
    }
    
    double findMedian() {
        if ((l.size() + r.size()) % 2)
            return *--l.end();
        return (*--l.end() + *r.begin()) / 2.0;
    }
};