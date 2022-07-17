class MyCircularDeque {
    vector<int> v;
    int head = 0, tail = 0, size = 0;
    
public:
    MyCircularDeque(int k) : v(k) {}
    
    bool insertFront(int value) {
        if (isFull())
            return 0;
        
        v[head] = value;
        head = (head + v.size() - 1) % v.size();
        size++;
        return 1;
    }
    
    bool insertLast(int value) {
        if (isFull())
            return 0;
        
        tail = (tail + 1) % v.size();
        v[tail] = value;
        size++;
        return 1;
        
    }
    
    bool deleteFront() {
        if (isEmpty())
            return 0;

        head = (head + 1) % v.size();
        size--;
        return 1;
    }
    
    bool deleteLast() {
        if (isEmpty())
            return 0;

        tail = (tail + v.size() - 1) % v.size();
        size--;
        return 1;
    }
    
    int getFront() {
        return isEmpty() ? -1 : v[(head + 1) % v.size()];
    }
    
    int getRear() {
        return isEmpty() ? -1 : v[tail];
    }
    
    bool isEmpty() {
        return !size;
    }
    
    bool isFull() {
        return size == v.size();
    }
};