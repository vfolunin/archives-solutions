struct Event {
    enum { BEGIN, POINT, END } type;
    int coord, index;
    
    bool operator < (const Event &that) const {
        if (coord != that.coord)
            return coord < that.coord;
        return type < that.type;
    }
};

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &segments, vector<int> &points) {
        vector<Event> events;
        
        for (vector<int> &segment : segments) {
            events.push_back({ Event::BEGIN, segment[0], 0 });
            events.push_back({ Event::END, segment[1], 0 });
        }
        
        for (int i = 0; i < points.size(); i++)
            events.push_back({ Event::POINT, points[i], i });
        
        sort(events.begin(), events.end());
        
        vector<int> res(points.size());
        int segmentCount = 0;
        
        for (auto &[type, coord, index] : events) {
            if (type == Event::BEGIN)
                segmentCount++;
            else if (type == Event::END)
                segmentCount--;
            else
                res[index] = segmentCount;
        }
        
        return res;
    }
};