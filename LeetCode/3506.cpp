class Solution {
    bool can(vector<int> &time, int splitTime, long long limit) {
        vector<long long> q(1);
        for (int ti = 0, qi = 0; ti < time.size(); qi++) {
            if (qi < q.size() && q[qi] + splitTime + time[ti] <= limit && q.size() - qi < time.size() - ti) {
                q.push_back(q[qi] + splitTime);
                q.push_back(q[qi] + splitTime);
            } else if (qi < q.size() && q[qi] + time[ti] <= limit) {
                ti++;
            } else {
                return 0;
            }
        }
        return 1;
    }

public:
    long long minEliminationTime(vector<int> &time, int splitTime) {
        sort(time.rbegin(), time.rend());

        long long l = 0, r = 1;
        while (!can(time, splitTime, r))
            r *= 2;
        
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (can(time, splitTime, m))
                r = m;
            else
                l = m;
        }

        return r;
    }
};