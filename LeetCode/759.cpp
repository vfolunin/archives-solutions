class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> &schedule) {
        map<int, int> delta;
        for (vector<Interval> &schedule : schedule) {
            for (Interval &interval : schedule) {
                delta[interval.start]++;
                delta[interval.end]--;
            }
        }
        
        for (auto it = delta.begin(); it != delta.end(); ) {
            if (it->second)
                it++;
            else
                it = delta.erase(it);
        }

        int cur = 0, from = -1;
        vector<Interval> res;

        for (auto &[time, delta] : delta) {
            if (!cur && from != -1)
                res.push_back(Interval(from, time));
            cur += delta;
            if (!cur)
                from = time;
        }
        
        return res;
    }
};