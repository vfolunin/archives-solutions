class Solution {
    bool can(vector<int> &tasks, vector<int> &workers, int pills, int delta, int pairCount) {
        multiset<int> taskSet(tasks.begin(), tasks.begin() + pairCount);
        
        for (int i = 0; i < pairCount; i++) {
            int workerStrength = workers[workers.size() - pairCount + i];
            
            if (auto it = taskSet.upper_bound(workerStrength); it != taskSet.begin()) {
                taskSet.erase(prev(it));
                continue;
            }
            
            if (auto it = taskSet.upper_bound(workerStrength + delta); pills && it != taskSet.begin()) {
                taskSet.erase(prev(it));
                pills--;
                continue;
            }
            
            return 0;
        }
        
        return 1;
    }
    
public:
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int delta) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        
        int l = 0, r = min(tasks.size(), workers.size()) + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(tasks, workers, pills, delta, m))
                l = m;
            else
                r = m;
        }        
        return l;
    }
};