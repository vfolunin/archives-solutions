class Solution {
public:
    int minProcessingTime(vector<int> &processors, vector<int> &tasks) {
        sort(processors.begin(), processors.end());
        sort(tasks.rbegin(), tasks.rend());

        int res = 0;
        for (int i = 0; i < processors.size(); i++)
            res = max(res, processors[i] + tasks[i * 4]);
        return res;
    }
};