class Solution {
public:
    int minimumFinishTime(vector<vector<int>> &tires, int changeTime, int lapCount) {
        vector<long long> lapsTime(20, 1e18);
        lapsTime[0] = 0;

        for (vector<int> &tire : tires) {
            long long lapTime = 0, totalTime = 0;

            for (int laps = 1; laps < lapsTime.size() && totalTime < changeTime; laps++) {
                lapTime = (laps == 1 ? lapTime + tire[0] : lapTime * tire[1]);
                totalTime += lapTime;
                
                lapsTime[laps] = min(lapsTime[laps], totalTime);
            }
        }

        vector<long long> res(lapCount + 1, 1e18);
        res[0] = 0;

        for (int laps = 1; laps <= lapCount; laps++)
            for (int lastLaps = 1; lastLaps <= laps && lastLaps < lapsTime.size(); lastLaps++)
                res[laps] = min(res[laps], res[laps - lastLaps] + changeTime + lapsTime[lastLaps]);

        return res[lapCount] - changeTime;
    }
};