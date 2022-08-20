class Solution {
public:
    long long taskSchedulerII(vector<int> &tasks, int space) {
        unordered_map<int, long long> last;
        long long time = 0;
        
        for (int task : tasks) {
            time = max(time + 1, last.count(task) ? last[task] + space + 1 : 0);
            last[task] = time;
        }
        
        return time;
    }
};