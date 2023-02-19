class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>> &a, vector<vector<int>> &b, int duration) {
        map<int, int> events;
        for (vector<int> &segment : a) {
            events[segment[0]]++;
            events[segment[1]]--;
        }
        for (vector<int> &segment : b) {
            events[segment[0]]++;
            events[segment[1]]--;
        }

        int free = 0;
        for (auto it = events.begin(); it != events.end(); it++) {
            free += it->second;
            if (free == 2 && it->first + duration <= next(it)->first)
                return { it->first, it->first + duration };
        }

        return {};
    }
};