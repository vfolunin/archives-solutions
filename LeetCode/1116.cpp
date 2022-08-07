class ZeroEvenOdd {
private:
    int i = 1, n;
    mutex m;
    condition_variable cv;
    
    void process(function<bool(int)> predicate, function<void()> print) {
        while (i <= n) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]() { return i > n || predicate(i); });
            if (i <= n)
                print();
            i++;
            lock.unlock();
            cv.notify_all();
        }        
    }

public:
    ZeroEvenOdd(int n) : n(2 * n) {}

    void zero(function<void(int)> printNumber) {
        process([](int i) { return i % 2; }, [&]() { printNumber(0); });
    }

    void even(function<void(int)> printNumber) {
        process([](int i) { return i % 2 == 0 && i / 2 % 2 == 0; }, [&]() { printNumber(i / 2); });
    }

    void odd(function<void(int)> printNumber) {
        process([](int i) { return i % 2 == 0 && i / 2 % 2; }, [&]() { printNumber(i / 2); });        
    }
};