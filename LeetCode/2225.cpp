class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches) {
        map<int, int> losses;
        for (vector<int> &match : matches) {
            losses[match[0]];
            losses[match[1]]++;
        }
        
        vector<vector<int>> res(2);
        for (auto &[id, lossCount] : losses)
            if (lossCount <= 1)
                res[lossCount].push_back(id);
        return res;
    }
};