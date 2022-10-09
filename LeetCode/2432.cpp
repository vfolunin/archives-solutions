class Solution {
public:
    int hardestWorker(int employeeCount, vector<vector<int>> &logs) {
        int res = 0, resTime = 0;
        
        for (int i = 0; i < logs.size(); i++) {
            int time = logs[i][1] - (i ? logs[i - 1][1] : 0);
            if (resTime < time || resTime == time && res > logs[i][0]) {
                resTime = time;
                res = logs[i][0];
            }
        }
        
        return res;
    }
};