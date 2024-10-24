class MyStack {
    stack<int> values, minimums;

public:
    void push(int value) {
        minimums.push(minimums.empty() || value < minimums.top() ? value : minimums.top());
        values.push(value);
    }

    int pop() {
        int res = values.top();
        values.pop();
        minimums.pop();
        return res;
    }

    int top() {
        return values.top();
    }

    int GetMin() {
        return minimums.top();
    }

    int GetSize() {
        return values.size();
    }
};
