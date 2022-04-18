class MyQueue {
    vector<int> l, r;
    
    void move() {
        while (!r.empty()) {
            l.push_back(r.back());
            r.pop_back();
        }
    }
    
public:
    void push(int x) {
        r.push_back(x);
    }
    
    int pop() {
        if (l.empty())
            move();
        int res = l.back();
        l.pop_back();
        return res;
    }
    
    int peek() {
        if (l.empty())
            move();
        return l.back();
    }
    
    bool empty() {
        return l.empty() && r.empty();
    }
};