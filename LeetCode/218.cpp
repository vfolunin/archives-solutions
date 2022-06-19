class Solution {
    struct Event {
        int x, y;
        enum { BEGIN, END } type;
        
        bool operator < (const Event &that) const {
            if (x != that.x)
                return x < that.x;
            if (type != that.type)
                return type < that.type;
            if (type == BEGIN)
                return y > that.y;
            else
                return y < that.y;
        }
    };
    
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        vector<Event> events;
        for (int i = 0; i < buildings.size(); i++) {
            events.push_back({ buildings[i][0], buildings[i][2], Event::BEGIN });
            events.push_back({ buildings[i][1], buildings[i][2], Event::END });
        }
        sort(events.begin(), events.end());
        
        vector<vector<int>> res;
        multiset<int> ys = {0};
        
        for (auto &[x, y, type] : events) {
            if (type == Event::BEGIN) {
                if (*prev(ys.end()) < y)
                    res.push_back({ x, y });
                ys.insert(y);                
            } else {
                if (*prev(prev(ys.end())) < y)
                    res.push_back({ x, *prev(prev(ys.end())) });
                ys.erase(ys.find(y));
            }
        }
        
        return res;
    }
};