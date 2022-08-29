class Solution {
public:
    int smallestChair(vector<vector<int>> &segments, int target) {
        vector<pair<int, int>> events;
        for (int i = 0; i < segments.size(); i++) {
            events.push_back({ segments[i][0], i + 1 });
            events.push_back({ segments[i][1], -i - 1 });
        }
        sort(events.begin(), events.end());
        
        set<int> seats;
        for (int i = 0; i < segments.size(); i++)
            seats.insert(i);
        
        vector<int> seatOf(segments.size());
        
        for (auto &[time, index] : events) {
            if (index > 0) {
                seatOf[index - 1] = *seats.begin();
                seats.erase(seats.begin());
            } else {
                seats.insert(seatOf[-index - 1]);
            }
        }
        
        return seatOf[target];
    }
};