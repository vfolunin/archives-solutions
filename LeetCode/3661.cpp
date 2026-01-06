class Solution {
    pair<int, int> getWallRange(vector<pair<int, int>> &pairs, vector<int> &walls, int i, int direction) {
        int l = pairs[i].first, r = pairs[i].first;
        if (!direction)
            l -= pairs[i].second;
        else
            r += pairs[i].second;
        
        if (i)
            l = max(l, pairs[i - 1].first);
        if (i + 1 < pairs.size())
            r = min(r, pairs[i + 1].first);
        
        l = lower_bound(walls.begin(), walls.end(), l) - walls.begin();
        r = upper_bound(walls.begin(), walls.end(), r) - walls.begin();
        return { l, r };
    }

public:
    int maxWalls(vector<int> &robots, vector<int> &limit, vector<int> &walls) {
        vector<pair<int, int>> pairs(robots.size());
        for (int i = 0; i < pairs.size(); i++)
            pairs[i] = { robots[i], limit[i] };
        sort(pairs.begin(), pairs.end());

        sort(walls.begin(), walls.end());

        vector<vector<int>> res(pairs.size(), vector<int>(2));
        for (int i = 0; i < res.size(); i++) {
            for (int direction = 0; direction < 2; direction++) {
                auto [l, r] = getWallRange(pairs, walls, i, direction);
                if (i) {
                    for (int prevDirection = 0; prevDirection < 2; prevDirection++) {
                        l = max(l, getWallRange(pairs, walls, i - 1, prevDirection).second);
                        res[i][direction] = max(res[i][direction], res[i - 1][prevDirection] + r - l);
                    }
                } else {
                    res[i][direction] = r - l;
                }
            }
        }
        return max(res.back()[0], res.back()[1]);
    }
};