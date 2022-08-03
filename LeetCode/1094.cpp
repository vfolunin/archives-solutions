class Solution {
public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        vector<pair<int, int>> events;
        for (vector<int> &trip : trips) {
            events.push_back({ trip[1], trip[0] });
            events.push_back({ trip[2], -trip[0] });
        }
        sort(events.begin(), events.end());
        
        for (auto &[coord, delta] : events) {
            capacity -= delta;
            if (capacity < 0)
                return 0;
        }
        return 1;
    }
};