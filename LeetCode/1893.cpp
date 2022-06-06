class Solution {
public:
    bool isCovered(vector<vector<int>> &ranges, int l, int r) {
        sort(ranges.begin(), ranges.end());
        for (vector<int> &range : ranges)
            if (range[0] <= l)
                l = max(l, range[1] + 1);
        return l > r;
    }
};