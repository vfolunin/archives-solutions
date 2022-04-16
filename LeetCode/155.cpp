class MinStack {
    vector<int> vals;
    vector<int> mins;
    
public:
    void push(int x) {
        vals.push_back(x);
        mins.push_back(mins.empty() || x < mins.back() ? x : mins.back());
    }
    
    void pop() {
        vals.pop_back();
        mins.pop_back();
    }
    
    int top() {
        return vals.back();
    }
    
    int getMin() {
        return mins.back();
    }
};