class Solution {    
public:
    int mostBooked(int roomCount, vector<vector<int>> &meetings) {
        set<int> available;
        for (int i = 0; i < roomCount; i++)
            available.insert(i);
        set<pair<long long, int>> busy;
        
        vector<int> meetingCount(roomCount);
        
        sort(meetings.begin(), meetings.end());
        for (vector<int> &meeting : meetings) {
            while (!busy.empty() && busy.begin()->first <= meeting[0]) {
                available.insert(busy.begin()->second);
                busy.erase(busy.begin());
            }
            
            if (available.empty()) {
                auto [time, room] = *busy.begin();
                meetingCount[room]++;
                busy.erase(busy.begin());
                busy.insert({ time + meeting[1] - meeting[0], room });
            } else {
                meetingCount[*available.begin()]++;
                busy.insert({ meeting[1], *available.begin() });
                available.erase(available.begin());
            }
        }
        
        return max_element(meetingCount.begin(), meetingCount.end()) - meetingCount.begin();
    }
};