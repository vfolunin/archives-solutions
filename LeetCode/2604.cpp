class Solution {
    bool can(vector<int> &a, vector<int> &b, long long time) {
        int bi = 0;

        for (int ai = 0; ai < a.size() && bi < b.size(); ai++) {
            long long rightTime = time;

            if (b[bi] < a[ai]) {
                long long leftTime = a[ai] - b[bi];
                if (leftTime > time)
                    return 0;
                
                rightTime = max(time - leftTime * 2, (time - leftTime) / 2);                
            }

            while (bi < b.size() && b[bi] <= a[ai] + rightTime)
                bi++;
        }

        return bi == b.size();
    }

public:
    int minimumTime(vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        long long l = -1, r = 1;
        while (!can(a, b, r))
            r *= 2;
        
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (can(a, b, m))
                r = m;
            else
                l = m;
        }

        return r;
    }
};