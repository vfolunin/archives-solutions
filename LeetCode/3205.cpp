class Solution {
public:
    int maxScore(vector<int> &a) {
        vector<int> res(a.size(), -1e9);
        res[0] = 0;

        for (int to = 0; to < a.size(); to++)
            for (int from = 0; from < to; from++)
                res[to] = max(res[to], res[from] + (to - from) * a[to]);

        return res.back();
    }
};