class Solution {
public:
    int maximizeTheProfit(int size, vector<vector<int>> &segments) {
        sort(segments.begin(), segments.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        vector<int> res(size);
        for (int i = 0, si = 0; i < size; i++) {
            if (i)
                res[i] = res[i - 1];

            while (si < segments.size() && segments[si][1] == i) {
                res[i] = max(res[i], (segments[si][0] ? res[segments[si][0] - 1] : 0) + segments[si][2]);
                si++;
            }
        }

        return res.back();
    }
};