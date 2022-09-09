template<typename T>
class TwoHeaps {
    multiset<T> l, r;
    int lSize = 0;
    
    void rebalance() {
        while (l.size() < lSize) {
            l.insert(*r.begin());
            r.erase(r.begin());
        }
        while (l.size() > lSize) {
            r.insert(*--l.end());
            l.erase(--l.end());
        }
    }
    
public:
    void insert(const T &value) {
        if (l.empty() || value <= *prev(l.end()))
            l.insert(value);
        else
            r.insert(value);
        rebalance();
    }
    
    T get() {
        T value = *r.begin();
        lSize++;
        rebalance();
        return value;
    }
};

class SORTracker {
    TwoHeaps<pair<int, string>> h;
    
public:
    void add(string name, int score) {
        h.insert({ -score, name });
    }
    
    string get() {
        return h.get().second;
    }
};