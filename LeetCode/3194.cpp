class Solution {
public:
    double minimumAverage(vector<int> &a) {
        sort(a.begin(), a.end());

        int res = 1e9;
        for (int l = 0, r = a.size() - 1; l < r; l++, r--)
            res = min(res, a[l] + a[r]);
        return res / 2.0;
    }
};