struct Event {
    int time;
    enum { CALL, QUERY } type;
    int arg;

    bool operator < (const Event &that) const {
        if (time != that.time)
            return time < that.time;
        return type < that.type;
    }
};

class Solution {
public:
    vector<int> countServers(int serverCount, vector<vector<int>> &logs, int interval, vector<int> &queries) {
        vector<Event> events;

        for (vector<int> &log : logs)
            events.push_back({ log[1], Event::CALL, log[0] });

        for (int i = 0; i < queries.size(); i++)
            events.push_back({ queries[i], Event::QUERY, i });

        sort(events.begin(), events.end());

        deque<Event> callEvents;
        unordered_map<int, int> calls;
        vector<int> res(queries.size());

        for (Event &event : events) {
            while (!callEvents.empty() && callEvents.front().time + interval < event.time) {
                if (!--calls[callEvents.front().arg])
                    calls.erase(callEvents.front().arg);
                callEvents.pop_front();
            }

            if (event.type == Event::CALL) {
                calls[event.arg]++;
                callEvents.push_back(event);
            } else {
                res[event.arg] = serverCount - calls.size();
            }
        }

        return res;
    }
};