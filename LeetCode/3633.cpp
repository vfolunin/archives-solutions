class Solution {
public:
    int earliestFinishTime(vector<int> &aStart, vector<int> &aTime, vector<int> &bStart, vector<int> &bTime) {
        int res = 1e9;
        for (int ai = 0; ai < aStart.size(); ai++)
            for (int bi = 0; bi < bStart.size(); bi++)
                res = min({ res, max(aStart[ai] + aTime[ai], bStart[bi]) + bTime[bi], max(bStart[bi] + bTime[bi], aStart[ai]) + aTime[ai] });
        return res;
    }
};