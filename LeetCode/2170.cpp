class Solution {
public:
    int minimumOperations(vector<int> &a) {
        vector<unordered_map<int, int>> count(2);
        for (int i = 0; i < a.size(); i++)
            count[i % 2][a[i]]++;
        
        vector<vector<pair<int, int>>> pairs(count.size());
        for (int i = 0; i < pairs.size(); i++) {
            pairs[i] = { count[i].begin(), count[i].end() };
            pairs[i].push_back({ -1 - i, 0 });
            sort(pairs[i].begin(), pairs[i].end(), [](auto &a, auto &b) {
                return a.second > b.second;
            });
        }
        
        int res = a.size();
        
        for (int i0 = 0; i0 < 3 && i0 < pairs[0].size(); i0++)
            for (int i1 = 0; i1 < 3 && i1 < pairs[1].size(); i1++)
                if (pairs[0][i0].first != pairs[1][i1].first)
                    res = min<int>(res, a.size() - pairs[0][i0].second - pairs[1][i1].second);
        
        return res;
    }
};