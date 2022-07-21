class FrontMiddleBackQueue {
    deque<int> a, b;
    
    void rebalance() {
        while (a.size() + 1 < b.size()) {
            a.push_back(b.front());
            b.pop_front();
        }
        while (a.size() > b.size()) {
            b.push_front(a.back());
            a.pop_back();
        }
    }
    
public:    
    void pushFront(int val) {
        a.push_front(val);
        rebalance();
    }
    
    void pushMiddle(int val) {
        a.push_back(val);
        rebalance();
    }
    
    void pushBack(int val) {
        b.push_back(val);
        rebalance();
    }
    
    int popFront() {
        if (a.empty() && b.empty())
            return -1;
        if (a.empty()) {
            int res = b.front();
            b.pop_front();
            return res;
        }
        int res = a.front();
        a.pop_front();
        rebalance();
        return res;
    }
    
    int popMiddle() {
        if (a.empty() && b.empty())
            return -1;
        if (a.size() == b.size()) {
            int res = a.back();
            a.pop_back();
            return res;
        }
        int res = b.front();
        b.pop_front();
        rebalance();
        return res;
    }
    
    int popBack() {
        if (a.empty() && b.empty())
            return -1;
        int res = b.back();
        b.pop_back();
        rebalance();
        return res;
    }
};