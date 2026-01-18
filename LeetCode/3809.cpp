class Solution {
public:
    vector<int> bestTower(vector<vector<int>> &towers, vector<int> &center, int radius) {
        vector<int> res = { -1, -1, -1 };
        for (vector<int> &tower : towers)
            if (abs(tower[0] - center[0]) + abs(tower[1] - center[1]) <= radius &&
                (res[2] < tower[2] || res[2] == tower[2] && res > tower))
                res = tower;
        return { res[0], res[1] };
    }
};