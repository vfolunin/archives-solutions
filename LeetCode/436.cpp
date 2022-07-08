class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>> &segments) {
        set<pair<int, int>> begins, ends;
        for (int i = 0; i < segments.size(); i++) {
            begins.insert({ segments[i][0], i });
            ends.insert({ segments[i][1], i });
        }
        
        vector<int> res(segments.size(), -1);
        for (auto [x, i] : begins) {
            while (!ends.empty() && ends.begin()->first <= x) {
                res[ends.begin()->second] = i;
                ends.erase(ends.begin());
            }
        }
        return res;
    }
};