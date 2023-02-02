struct Event {
    int time;
    enum { END, BEGIN } type;

    bool operator < (const Event &that) const {
        if (time != that.time)
            return time < that.time;
        return type < that.type;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>> &segments) {
        vector<Event> events;
        for (vector<int> &segment : segments) {
            events.push_back({ segment[0], Event::BEGIN });
            events.push_back({ segment[1], Event::END });
        }
        sort(events.begin(), events.end());

        int cur = 0, res = 0;
        for (auto &[time, type] : events) {
            cur += type == Event::BEGIN ? 1 : -1;
            res = max(res, cur);
        }
        return res;
    }
};