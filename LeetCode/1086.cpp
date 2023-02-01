class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>> &items) {
        map<int, multiset<int>> scores;
        for (vector<int> &item : items) {
            scores[item[0]].insert(item[1]);
            if (scores[item[0]].size() > 5)
                scores[item[0]].erase(scores[item[0]].begin());
        }
        
        vector<vector<int>> res;
        for (auto &[id, scores] : scores)
            res.push_back({ id, accumulate(scores.begin(), scores.end(), 0) / 5 });
        return res;
    }
};