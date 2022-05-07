class Solution {
public:
    vector<string> findRelativeRanks(vector<int> &score) {
        vector<pair<int, int>> pairs(score.size());
        for (int i = 0; i < score.size(); i++)
            pairs[i] = { -score[i], i };
        sort(pairs.begin(), pairs.end());
        
        vector<string> res(score.size());
        for (int i = 0; i < pairs.size(); i++) {
            if (i == 0)
                res[pairs[i].second] = "Gold Medal";
            else if (i == 1)
                res[pairs[i].second] = "Silver Medal";
            else if (i == 2)
                res[pairs[i].second] = "Bronze Medal";
            else
                res[pairs[i].second] = to_string(i + 1);
        }
        
        return res;
    }
};