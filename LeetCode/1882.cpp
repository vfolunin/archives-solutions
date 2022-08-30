class Solution {    
public:
    vector<int> assignTasks(vector<int> &serverWeights, vector<int> &tasks) {
        set<pair<int, int>> available;
        map<int, vector<pair<int, int>>> busy;
        
        for (int i = 0; i < serverWeights.size(); i++)
            available.insert({ serverWeights[i], i });
        
        vector<int> res(tasks.size());
        
        for (int i = 0, time = 0; i < tasks.size(); time++) {
            if (available.empty() && time < busy.begin()->first)
                time = busy.begin()->first;
            
            while (!busy.empty() && busy.begin()->first <= time) {
                for (pair<int, int> &server : busy.begin()->second)
                    available.insert(server);
                busy.erase(busy.begin());
            }
            
            for ( ; !available.empty() && i <= time && i < tasks.size(); i++) {
                auto [weight, index] = *available.begin();
                available.erase(available.begin());
                res[i] = index;
                busy[time + tasks[i]].push_back({ weight, index });
            }
        }
        
        return res;
    }
};