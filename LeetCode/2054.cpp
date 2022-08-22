class Solution {
    struct Event {
        int time, type, value;
        
        bool operator < (const Event &that) const {
            if (time != that.time)
                return time < that.time;
            return type < that.type;
        }
    };
    
public:
    int maxTwoEvents(vector<vector<int>> &segments) {
        vector<Event> events;
        for (vector<int> &segment : segments) {
            events.push_back({ segment[0], 0, segment[2] });
            events.push_back({ segment[1], 1, segment[2] });
        }
        sort(events.begin(), events.end());
        
        int maxValue = 0, res = 0;
        
        for (auto &[time, type, value] : events) {
            if (!type)
                res = max(res, maxValue + value);
            else
                maxValue = max(maxValue, value);
        }
        
        return res;
    }
};