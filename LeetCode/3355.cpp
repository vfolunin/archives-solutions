class Solution {
public:
    bool isZeroArray(vector<int> &a, vector<vector<int>> &queries) {
        vector<int> deltas(a.size() + 1);
        for (vector<int> &query : queries) {
            deltas[query[0]]++;
            deltas[query[1] + 1]--;
        }

        int totalDelta = 0;
        for (int i = 0; i < a.size(); i++) {
            totalDelta += deltas[i];
            if (a[i] > totalDelta)
                return 0;
        }
        return 1;
    }
};
