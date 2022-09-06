class Solution {
    int rec(int mask, int time, vector<int> &tasks, int sessionTime, vector<vector<int>> &memo) {
        int &res = memo[mask][time];
        if (res != -1)
            return res;
        
        if (!mask)
            return res = 0;
        
        res = 1e9;
        
        for (int bit = 0; bit < tasks.size(); bit++) {
            if (mask & (1 << bit)) {
                if (tasks[bit] <= time)
                    res = min(res, rec(mask ^ (1 << bit), time - tasks[bit], tasks, sessionTime, memo));
                else
                    res = min(res, 1 + rec(mask ^ (1 << bit), sessionTime - tasks[bit], tasks, sessionTime, memo));
            }
        }
        
        return res;
    }
    
public:
    int minSessions(vector<int> &tasks, int sessionTime) {
        vector<vector<int>> memo(1 << tasks.size(), vector<int>(16, -1));
        return rec(memo.size() - 1, 0, tasks, sessionTime, memo);
    }
};