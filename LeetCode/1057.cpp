class Solution {
    int dist(vector<int> &a, vector<int> &b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

public:
    vector<int> assignBikes(vector<vector<int>> &a, vector<vector<int>> &b) {
        vector<pair<int, int>> pairs;
        for (int ai = 0; ai < a.size(); ai++)
            for (int bi = 0; bi < b.size(); bi++)
                pairs.push_back({ ai, bi });
        
        sort(pairs.begin(), pairs.end(), [&](auto &lhs, auto &rhs) {
            int lDist = dist(a[lhs.first], b[lhs.second]);
            int rDist = dist(a[rhs.first], b[rhs.second]);
            if (lDist != rDist)
                return lDist < rDist;
            if (lhs.first != rhs.first)
                return lhs.first < rhs.first;
            return lhs.second < rhs.second;
        });

        vector<int> aUsed(a.size()), bUsed(b.size()), res(a.size());
        for (auto &[ai, bi] : pairs) {
            if (!aUsed[ai] && !bUsed[bi]) {
                aUsed[ai] = bUsed[bi] = 1;
                res[ai] = bi;
            }
        }
        return res;
    }
};