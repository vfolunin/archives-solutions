class Solution {
public:
    vector<vector<int>> averageHeightOfBuildings(vector<vector<int>> &segments) {
        map<int, pair<int, int>> delta;
        for (vector<int> &segment : segments) {
            delta[segment[0]].first += segment[2];
            delta[segment[0]].second++;
            delta[segment[1]].first -= segment[2];
            delta[segment[1]].second--;
        }

        int num = 0, den = 0;
        vector<vector<int>> res;
        for (auto &[x, delta] : delta) {
            int prevDen = den;
            num += delta.first;
            den += delta.second;

            if (prevDen)
                res.back()[1] = x;
            if (!prevDen || den && res.back()[2] != num / den)
                res.push_back({ x, x, num / den });
        }
        return res;
    }
};