class MyStack {
    deque<int> q;
    
public:
    void push(int x) {
        q.push_back(x);
    }
    
    int pop() {
        int res = q.back();
        q.pop_back();
        return res;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};