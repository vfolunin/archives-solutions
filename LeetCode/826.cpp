class Solution {
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &workers) {
        vector<pair<int, int>> pairs(difficulty.size());
        for (int i = 0; i < pairs.size(); i++) {
            pairs[i].first = difficulty[i];
            pairs[i].second = profit[i];
        }
        
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second > b.second;
        });
        
        for (int i = 1; i < pairs.size(); i++)
            pairs[i].second = max(pairs[i].second, pairs[i - 1].second);
        
        int res = 0;
        for (int worker : workers)
            if (auto it = upper_bound(pairs.begin(), pairs.end(), make_pair(worker + 1, 0)); it != pairs.begin())
                res += prev(it)->second;
        return res;
    }
};