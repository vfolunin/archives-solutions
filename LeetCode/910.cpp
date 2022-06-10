class Solution {
public:
    int smallestRangeII(vector<int> &a, int k) {
        sort(a.begin(), a.end());
        int res = a.back() - a.front();
        for (int i = 0; i + 1 < a.size(); i++)
            res = min(res, max(a[i] + 2 * k, a.back()) - min(a.front() + 2 * k, a[i + 1]));
        return res;
    }
};