class EventManager {
    set<pair<int, int>> eventQueue;
    unordered_map<int, int> eventPriority;

    void insert(int eventId, int priority) {
        eventQueue.insert({ -priority, eventId });
        eventPriority[eventId] = priority;
    }

public:
    EventManager(vector<vector<int>> &events) {
        for (vector<int> &event : events) 
            insert(event[0], event[1]);
    }
    
    void updatePriority(int eventId, int newPriority) {
        if (auto it = eventPriority.find(eventId); it != eventPriority.end())
            eventQueue.erase({ -it->second, eventId });
        insert(eventId, newPriority);
    }
    
    int pollHighest() {
        if (eventQueue.empty())
            return -1;

        int res = eventQueue.begin()->second;
        eventQueue.erase(eventQueue.begin());
        return res;
    }
};