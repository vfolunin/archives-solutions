struct Event {
    int time;
    enum { BEGIN, END } type;

    bool operator < (const Event &that) const {
        if (time != that.time)
            return time < that.time;
        return type < that.type;
    }
};

class Solution {
public:
    int countDays(int maxTime, vector<vector<int>> &segments) {
        vector<Event> events;
        for (vector<int> &segment : segments) {
            events.push_back({ segment[0], Event::BEGIN });
            events.push_back({ segment[1], Event::END });
        }
        sort(events.begin(), events.end());

        int segmentCount = 0, from = 1, res = 0;
        for (auto &[time, type] : events) {
            if (type == Event::BEGIN) {
                if (!segmentCount)
                    res += time - from;
                segmentCount++;
            } else {
                segmentCount--;
            }
            from = time + 1;
        }
        res += maxTime - from + 1;

        return res;
    }
};