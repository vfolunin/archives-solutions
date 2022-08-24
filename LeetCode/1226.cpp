class DiningPhilosophers {
    vector<mutex> mutexes;
    
public:
    DiningPhilosophers() : mutexes(5) {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int a = philosopher;
        int b = (a + 1) % 5;
        if (a > b)
            swap(a, b);
        
        mutexes[a].lock();
        mutexes[b].lock();
        
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        
        mutexes[a].unlock();
        mutexes[b].unlock();
    }
};