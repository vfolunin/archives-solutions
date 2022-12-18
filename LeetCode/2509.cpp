class Solution {
    vector<int> getAncestors(int v) {
        vector<int> res;
        for ( ; v; v /= 2)
            res.push_back(v);
        return res;
    }

    int solve(int a, int b) {
        vector<int> aAncestors = getAncestors(a);
        vector<int> bAncestors = getAncestors(b);
        while (!aAncestors.empty() && !bAncestors.empty() && aAncestors.back() == bAncestors.back()) {
            aAncestors.pop_back();
            bAncestors.pop_back();
        }
        return aAncestors.size() + bAncestors.size() + 1;
    }

public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries) {
        vector<int> res(queries.size());
        for (int i = 0; i < res.size(); i++)
            res[i] = solve(queries[i][0], queries[i][1]);
        return res;
    }
};