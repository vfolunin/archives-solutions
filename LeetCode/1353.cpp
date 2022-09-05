struct Event {
    int l, r;

    bool operator < (const Event &that) const {
        return r < that.r;
    }
};

class Solution {
public:
    int maxEvents(vector<vector<int>> &events) {
        sort(events.begin(), events.end());

        multiset<Event> ongoingEvents;
        int res = 0;

        for (int i = 0, curTime = 1; i < events.size() || !ongoingEvents.empty(); ) {
            for ( ; i < events.size() && events[i][0] <= curTime; i++)
                ongoingEvents.insert({ events[i][0], events[i][1] + 1 });

            if (!ongoingEvents.empty()) {
                ongoingEvents.erase(ongoingEvents.begin());
                res++;
                curTime++;
            } else if (i < events.size()) {
                curTime = events[i][0];
            }        

            while (!ongoingEvents.empty() && ongoingEvents.begin()->r <= curTime)
                ongoingEvents.erase(ongoingEvents.begin());
        }
        
        return res;
    }
};