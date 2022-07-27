class FooBar {
private:
    int n;
    mutex f, b;

public:
    FooBar(int n) : n(n) {
        b.lock();
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            f.lock();
        	printFoo();
            b.unlock();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            b.lock();
        	printBar();
            f.unlock();
        }
    }
};