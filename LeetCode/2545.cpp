class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> &a, int x) {
        sort(a.begin(), a.end(), [&](auto &lhs, auto &rhs) {
            return lhs[x] > rhs[x];
        });
        return a;
    }
};