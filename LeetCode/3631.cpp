class Solution {
public:
    vector<vector<int>> sortThreats(vector<vector<int>> &a) {
        sort(a.begin(), a.end(), [](auto &lhs, auto &rhs) {
            long long l = 2LL * lhs[1] + lhs[2];
            long long r = 2LL * rhs[1] + rhs[2];
            if (l != r)
                return l > r;
            return lhs[0] < rhs[0];
        });
        return a;
    }
};