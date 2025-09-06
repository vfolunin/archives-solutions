class StatisticsTracker {
    queue<int> q;
    long long sum = 0;
    multiset<int> l, r;
    unordered_map<int, int> count;
    set<pair<int, int>> counts;

    void rebalance() {
        while (l.size() + 1 < r.size()) {
            l.insert(*r.begin());
            r.erase(r.begin());
        }
        while (r.size() < l.size()) {
            r.insert(*--l.end());
            l.erase(--l.end());
        }
    }

    void addLR(int value) {
        if (r.empty() || value >= *r.begin())
            r.insert(value);
        else
            l.insert(value);
        rebalance();
    }

    void removeLR(int value) {
        if (auto it = l.find(value); it != l.end())
            l.erase(it);
        else
            r.erase(r.find(value));
        rebalance();
    }

    void changeCount(int value, int delta) {
        counts.erase({ -count[value], value });
        if (count[value] += delta)
            counts.insert({ -count[value], value });
    }

public:
    void addNumber(int value) {
        q.push(value);
        sum += value;
        addLR(value);
        changeCount(value, 1);
    }
    
    void removeFirstAddedNumber() {
        sum -= q.front();
        removeLR(q.front());
        changeCount(q.front(), -1);
        q.pop();
    }
    
    int getMean() {
        return sum / q.size();
    }
    
    int getMedian() {
        return *r.begin();
    }
    
    int getMode() {
        return counts.begin()->second;
    }
};