class Solution {
public:
    int maximumProcessableQueries(vector<int> &a, vector<int> &queries) {
        vector<vector<int>> count(a.size() + 1, vector<int>(a.size() + 1));
        int res = 0;

        for (int l = 0; l < a.size() && res < queries.size(); l++) {
            for (int r = a.size(); l <= r && res < queries.size(); r--) {
                if (l)
                    count[l][r] = max(count[l][r], count[l - 1][r] + (a[l - 1] >= queries[count[l - 1][r]]));
                if (r < a.size())
                    count[l][r] = max(count[l][r], count[l][r + 1] + (a[r] >= queries[count[l][r + 1]]));

                res = max(res, count[l][r]);
            }
        }

        return res;
    }
};