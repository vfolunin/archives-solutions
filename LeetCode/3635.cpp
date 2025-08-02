class Solution {
    vector<int> getMinTimeStartingBefore(vector<int> &start, vector<int> &time) {
        vector<int> order(start.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int lhs, int rhs) {
            return start[lhs] < start[rhs];
        });

        vector<int> minTime(2e5 + 1, 1e9);
        for (int t = 1, i = 0; t < minTime.size(); t++) {
            minTime[t] = minTime[t - 1];
            for ( ; i < order.size() && start[order[i]] == t; i++)
                minTime[t] = min(minTime[t], time[order[i]]);
        }
        return minTime;
    }

    vector<int> getMinFinishStartingAfter(vector<int> &start, vector<int> &time) {
        vector<int> order(start.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int lhs, int rhs) {
            return start[lhs] > start[rhs];
        });

        vector<int> minFinish(2e5 + 1, 1e9);
        for (int t = minFinish.size() - 1, i = 0; t; t--) {
            if (t + 1 < minFinish.size())
                minFinish[t] = minFinish[t + 1];
            for ( ; i < order.size() && start[order[i]] == t; i++)
                minFinish[t] = min(minFinish[t], start[order[i]] + time[order[i]]);
        }
        return minFinish;
    }

public:
    int earliestFinishTime(vector<int> &aStart, vector<int> &aTime, vector<int> &bStart, vector<int> &bTime) {
        vector<int> aMinTimeStartingBefore = getMinTimeStartingBefore(aStart, aTime);
        vector<int> aMinFinishStartingAfter = getMinFinishStartingAfter(aStart, aTime);
        
        vector<int> bMinTimeStartingBefore = getMinTimeStartingBefore(bStart, bTime);
        vector<int> bMinFinishStartingAfter = getMinFinishStartingAfter(bStart, bTime);

        int res = 1e9;
        for (int i = 0; i < aStart.size(); i++) {
            res = min(res, aStart[i] + aTime[i] + bMinTimeStartingBefore[aStart[i] + aTime[i]]);
            res = min(res, bMinFinishStartingAfter[aStart[i] + aTime[i]]);
        }
        for (int i = 0; i < bStart.size(); i++) {
            res = min(res, bStart[i] + bTime[i] + aMinTimeStartingBefore[bStart[i] + bTime[i]]);
            res = min(res, aMinFinishStartingAfter[bStart[i] + bTime[i]]);
        }
        return res;
    }
};