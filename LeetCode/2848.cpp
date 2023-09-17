class Solution {
public:
    int numberOfPoints(vector<vector<int>> &segments) {
        int res = 0;
        for (int coord = 1; coord <= 100; coord++) {
            bool covered = 0;
            for (vector<int> &segment : segments)
                covered |= segment[0] <= coord && coord <= segment[1];
            res += covered;
        }
        return res;
    }
};