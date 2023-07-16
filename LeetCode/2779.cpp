struct Event {
    int coord;
    enum { BEGIN, END } type;

    bool operator < (const Event &that) const {
        if (coord != that.coord)
            return coord < that.coord;
        return type < that.type;
    }
};

class Solution {
public:
    int maximumBeauty(vector<int> &a, int delta) {
        vector<Event> events;
        for (int coord : a) {
            events.push_back({ coord - delta, Event::BEGIN });
            events.push_back({ coord + delta, Event::END });
        }
        sort(events.begin(), events.end());

        int cur = 0, res = 0;
        for (auto &[coord, type] : events) {
            cur += type == Event::BEGIN ? 1 : -1;
            res = max(res, cur);
        }
        return res;
    }
};