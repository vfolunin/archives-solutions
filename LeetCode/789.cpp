class Solution {
public:
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target) {
        int dist = abs(target[0]) + abs(target[1]);
        for (vector<int> &ghost : ghosts)
            if (abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]) <= dist)
                return 0;
        return 1;
    }
};