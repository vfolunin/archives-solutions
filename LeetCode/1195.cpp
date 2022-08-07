class FizzBuzz {
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
    FizzBuzz(int n) : n(n) {}
    
    void fizzbuzz(function<void()> printFizzBuzz) {
        process([](int i) { return i % 15 == 0; }, printFizzBuzz);
    }

    void fizz(function<void()> printFizz) {
        process([](int i) { return i % 3 == 0 && i % 5; }, printFizz);
    }

    void buzz(function<void()> printBuzz) {
        process([](int i) { return i % 3 && i % 5 == 0; }, printBuzz);
    }

    void number(function<void(int)> printNumber) {
        process([](int i) { return i % 3 && i % 5; }, [&]() { printNumber(i); });
    }
};