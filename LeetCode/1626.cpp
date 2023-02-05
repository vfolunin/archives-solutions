class Solution {
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages) {
        vector<pair<int, int>> pairs(scores.size());
        for (int i = 0; i < pairs.size(); i++)
            pairs[i] = { scores[i], ages[i] };
        sort(pairs.begin(), pairs.end());
        
        vector<int> res(pairs.size());
        for (int i = 0; i < res.size(); i++) {
            res[i] = pairs[i].first;
            for (int j = 0; j < i; j++)
                if (pairs[j].second <= pairs[i].second)
                    res[i] = max(res[i], res[j] + pairs[i].first);
        }
        return *max_element(res.begin(), res.end());
    }
};