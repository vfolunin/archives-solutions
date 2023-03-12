class Solution {
public:
    int findMinimumTime(vector<vector<int>> &tasks) {
        sort(tasks.begin(), tasks.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int res = 0;

        for (int i = 1; i <= 2000; i++) {
            bool needUse = 0;
            for (vector<int> &task : tasks)
                needUse |= task[0] <= i && i <= task[1] && task[2] && i + task[2] > task[1];
            
            if (needUse) {
                for (vector<int> &task : tasks)
                    if (task[0] <= i && i <= task[1] && task[2])
                        task[2]--;
                res++;
            }
        }

        return res;
    }
};