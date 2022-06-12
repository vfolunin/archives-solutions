class RecentCounter {
    deque<int> times;
    
public:    
    int ping(int time) {
        while (!times.empty() && times.front() + 3000 < time)
            times.pop_front();
        times.push_back(time);
        return times.size();
    }
};