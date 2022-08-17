class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>> &segments) {
        map<int, long long> events;
        for (vector<int> &segment : segments) {
            events[segment[0]] += segment[2];
            events[segment[1]] -= segment[2];
        }
        
        vector<vector<long long>> res;
        long long sum = 0;
        for (auto it = events.begin(); next(it) != events.end(); it++) {
            sum += it->second;
            if (sum)
                res.push_back({ it->first, next(it)->first, sum });
        }
        return res;
    }
};