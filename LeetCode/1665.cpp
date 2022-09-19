class Solution {
    bool can(vector<vector<int>> &tasks, int energy) {
        for (vector<int> &task : tasks) {
            if (energy < task[1])
                return 0;
            energy -= task[0];
        }
        return 1;
    }
    
public:
    int minimumEffort(vector<vector<int>> &tasks) {
        sort(tasks.begin(), tasks.end(), [](auto &a, auto &b) {
            return a[1] - a[0] > b[1] - b[0];
        });
        
        int l = 0, r = 1e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(tasks, m))
                r = m;
            else
                l = m;
        }
        return r;
    }
};