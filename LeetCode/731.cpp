class MyCalendarTwo {
    map<int, int> events;
    
    bool check() {
        int sum = 0;
        for (auto &[time, delta] : events) {
            sum += delta;
            if (sum > 2)
                return 0;
        }
        return 1;
    }
    
public:    
    bool book(int l, int r) {
        events[l]++;
        events[r]--;
        
        if (!check()) {
            events[l]--;
            events[r]++;
            return 0;
        }
        
        return 1;
    }
};