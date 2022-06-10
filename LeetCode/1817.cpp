class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k) {
        unordered_map<int, unordered_set<int>> minutes;
        for (vector<int> &record : logs)
            minutes[record[0]].insert(record[1]);
        
        vector<int> res(k);
        for (auto &[id, minutes] : minutes)
            if (minutes.size() <= k)
                res[minutes.size() - 1]++;
        
        return res;
    }
};