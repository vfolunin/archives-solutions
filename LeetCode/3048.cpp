class Solution {
    bool can(vector<int> &a, vector<int> &pos, int limit) {
        vector<int> lastTime(a.size(), -1);
        for (int i = 0; i < limit && i < pos.size(); i++)
            lastTime[pos[i] - 1] = i;
        
        vector<int> order(a.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
            return lastTime[i] < lastTime[j];
        });

        long long usedTime = 0;
        for (int i : order) {
            if (usedTime + a[i] <= lastTime[i])
                usedTime += a[i] + 1;
            else
                return 0;
        }
        return 1;
    }

public:
    int earliestSecondToMarkIndices(vector<int> &a, vector<int> &pos) {
        int l = 0, r = pos.size() + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, pos, m))
                r = m;
            else
                l = m;
        }
        return r <= pos.size() ? r : -1;
    }
};