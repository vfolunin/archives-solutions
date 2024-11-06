template<typename T>
struct Stackable {
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T peek() = 0;
    virtual bool Empty() = 0;
    virtual int size() = 0;
};

template<typename T>
struct MyStack : public Stackable<T> {
    stack<T> s;
    
    void push(T value) {
        s.push(value);
    }
    
    T pop() {
        T res = s.top();
        s.pop();
        return res;
    }
    
    T peek() {
        return s.top();
    }
    
    bool Empty() {
        return s.empty();
    }
    
    int size() {
        return s.size();
    }
};