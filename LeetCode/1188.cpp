class BoundedBlockingQueue {
    int capacity;
    queue<int> q;
    mutex m;
    condition_variable cv;

public:
    BoundedBlockingQueue(int capacity) : capacity(capacity) {}
    
    void enqueue(int value) {
        unique_lock lock(m);
        cv.wait(lock, [&]() { return q.size() < capacity; });
        q.push(value);
        cv.notify_all();
    }
    
    int dequeue() {
        unique_lock lock(m);
        cv.wait(lock, [&]() { return !q.empty(); });
        int value = q.front();
        q.pop();
        cv.notify_all();
        return value;
    }
    
    int size() {
        unique_lock lock(m);
        return q.size();
    }
};