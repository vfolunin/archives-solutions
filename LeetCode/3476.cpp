class Solution {
public:
    long long maxProfit(vector<int> &workers, vector<vector<int>> &tasks) {
        unordered_map<int, multiset<int>> profits;
        multiset<int> allProfits;
        for (vector<int> &task : tasks) {
            profits[task[0]].insert(task[1]);
            allProfits.insert(task[1]);
        }

        long long res = 0;
        for (int worker : workers) {
            if (auto it = profits.find(worker); it != profits.end() && !it->second.empty()) {
                res += *prev(it->second.end());
                allProfits.erase(allProfits.find(*prev(it->second.end())));
                profits[worker].erase(prev(it->second.end()));
            }
        }
        if (!allProfits.empty())
            res += *prev(allProfits.end());
        return res;
    }
};