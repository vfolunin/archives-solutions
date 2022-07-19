class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        vector<int> taskCount(26);
        for (char task : tasks)
            taskCount[task - 'A']++;
        
        int maxCount = *max_element(taskCount.begin(), taskCount.end());
        int maxRep = count(taskCount.begin(), taskCount.end(), maxCount);
        
        int res = (maxCount - 1) * (n + 1) + maxRep;       
        return max<int>(res, tasks.size());        
    }
};