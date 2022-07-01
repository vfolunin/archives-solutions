class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &segments) {
        sort(segments.begin(), segments.end(), [](auto &a, auto &b) { return a[1] < b[1]; });
        
        int res = segments.size(), r = -1e9;
        for (vector<int> &segment : segments) {
            if (r <= segment[0]) {
                res--;
                r = segment[1];
            }
        }
        
        return res;
    }
};