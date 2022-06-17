class MyCircularQueue {
    vector<int> a;
    int head = 0, tail = 0, size = 0;
    
public:
    MyCircularQueue(int k) : a(k) {}
    
    bool enQueue(int value) {
        if (isFull())
            return 0;
        
        a[tail] = value;
        tail = (tail + 1) % a.size();
        size++;
        return 1;
    }
    
    bool deQueue() {
        if (isEmpty())
            return 0;
        
        head = (head + 1) % a.size();
        size--;
        return 1;
    }
    
    int Front() {
        if (isEmpty())
            return -1;
        
        return a[head];
    }
    
    int Rear() {
        if (isEmpty())
            return -1;
        
        return a[(tail + a.size() - 1) % a.size()];
    }
    
    bool isEmpty() {
        return !size;
    }
    
    bool isFull() {
        return size == a.size();
    }
};