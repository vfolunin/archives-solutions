class Solution {
    bool can(vector<pair<int, long long>> limit, int start, long long time) {
        for (auto &[floor, limit] : limit) {
            if (time < limit)
                return 0;
            limit = time - limit;
        }

        vector minTime(limit.size(), vector<long long>(2, 1e18));
        for (int i = 0; i < limit.size(); i++)
            minTime[i][0] = minTime[i][1] = 0;

        for (int len = 2; len <= limit.size(); len++) {
            for (int l = 0, r = len - 1; r < limit.size(); l++, r++) {
                long long lTime = min(minTime[l + 1][0] + limit[l + 1].first - limit[l].first,
                                      minTime[l + 1][1] + limit[r].first - limit[l].first);
                long long rTime = min(minTime[l][0] + limit[r].first - limit[l].first,
                                      minTime[l][1] + limit[r].first - limit[r - 1].first);

                minTime[l][0] = lTime <= limit[l].second ? lTime : 1e18;
                minTime[l][1] = rTime <= limit[r].second ? rTime : 1e18;
            }
        }

        return min(minTime[0][0] + abs(start - limit.front().first),
                   minTime[0][1] + abs(start - limit.back().first)) <= time;
    }

public:
    long long elevatorRequests(int floorCount, int start, vector<vector<int>> &requests) {
        map<int, int> lastTime;
        for (vector<int> &request : requests)
            lastTime[request[1]] = max(lastTime[request[1]], request[0]);

        long long l = -1, r = 1;
        while (!can({ lastTime.begin(), lastTime.end() }, start, r))
            r *= 2;
        
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (can({ lastTime.begin(), lastTime.end() }, start, m))
                r = m;
            else
                l = m;
        }
        return r;
    }
};