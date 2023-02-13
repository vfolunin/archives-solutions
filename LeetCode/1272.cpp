class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>> &intervals, vector<int> &toBeRemoved) {
        vector<vector<int>> res;

        for (vector<int> &interval : intervals) {
            int l = interval[0], r = interval[1];

            if (l < toBeRemoved[0] && toBeRemoved[1] < r) {
                res.push_back({ l, toBeRemoved[0] });
                res.push_back({ toBeRemoved[1], r });
            } else {
                if (toBeRemoved[0] <= l)
                    l = max(l, toBeRemoved[1]);
                if (r <= toBeRemoved[1])
                    r = min(r, toBeRemoved[0]);

                if (l < r)
                    res.push_back({ l, r });
            }
        }

        return res;
    }
};