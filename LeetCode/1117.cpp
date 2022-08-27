class H2O {
    int releasedH = 0, releasedO = 0;
    mutex m;
    condition_variable cv;
    
public:
    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock lock(m);        
        cv.wait(lock, [&]() { return releasedH <= 2 * releasedO; });
        releaseHydrogen();
        releasedH++;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock lock(m);        
        cv.wait(lock, [&]() { return releasedH >= 2 * releasedO; });
        releaseOxygen();
        releasedO++;
        cv.notify_all();
    }
};