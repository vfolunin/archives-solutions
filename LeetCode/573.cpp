class Solution {
    int dist(vector<int> &a, vector<int> &b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

public:
    int minDistance(int h, int w, vector<int> &tree, vector<int> &squirrel, vector<vector<int>> &nuts) {
        int res = 0, sub = -1e9;
        for (vector<int> &nut : nuts) {
            res += 2 * dist(nut, tree);
            sub = max(sub, dist(nut, tree) - dist(squirrel, nut));
        }
        return res - sub;
    }
};