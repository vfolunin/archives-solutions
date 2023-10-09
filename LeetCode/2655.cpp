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
    vector<vector<int>> findMaximalUncoveredRanges(int size, vector<vector<int>> &segments) {
        vector<Event> events;
        for (vector<int> &segment : segments) {
            events.push_back({ segment[0], Event::BEGIN });
            events.push_back({ segment[1], Event::END });
        }

        sort(events.begin(), events.end());

        vector<vector<int>> res;
        int segmentCount = 0, to = 0;

        for (auto &[coord, type] : events) {
            if (type == Event::BEGIN) {
                if (!segmentCount && to < coord)
                    res.push_back({ to, coord - 1 });
                segmentCount++;
            } else {
                segmentCount--;
                if (!segmentCount)
                    to = coord + 1;
            }
        }
        if (!segmentCount && to < size)
            res.push_back({ to, size - 1 });
        
        return res;
    }
};