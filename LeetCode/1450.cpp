class Solution {
public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime) {
        int res = 0;
        for (int i = 0; i < startTime.size(); i++)
            res += startTime[i] <= queryTime && queryTime <= endTime[i];
        return res;
    }
};