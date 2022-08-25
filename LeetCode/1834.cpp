class Solution {
public:
    vector<int> getOrder(vector<vector<int>> &tasks) {
        vector<int> indexes(tasks.size());
        iota(indexes.begin(), indexes.end(), 0);
        sort(indexes.begin(), indexes.end(), [&](int a, int b) {
            return tasks[a] < tasks[b];
        });
        
        long long time = 0;
        set<pair<int, int>> available;
        vector<int> res(tasks.size());
        
        for (int i = 0, ii = 0; i < res.size(); i++) {
            if (available.empty())
                time = max<long long>(time, tasks[indexes[ii]][0]);
            
            while (ii < indexes.size() && tasks[indexes[ii]][0] <= time) {
                available.insert({ tasks[indexes[ii]][1], indexes[ii] });
                ii++;
            }
            
            time += available.begin()->first;
            res[i] = available.begin()->second;
            available.erase(available.begin());
        }
        
        return res;
    }
};