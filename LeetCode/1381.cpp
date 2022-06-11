class CustomStack {
    vector<int> stack;
    int size = 0;
    
public:
    CustomStack(int maxSize) : stack(maxSize) {}
    
    void push(int x) {
        if (size < stack.size())
            stack[size++] = x;
    }
    
    int pop() {
        return size ? stack[--size] : -1;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < size && i < k; i++)
            stack[i] += val;
    }
};