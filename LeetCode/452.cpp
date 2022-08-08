class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &segments) {
        sort(segments.begin(), segments.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        
        int count = 1, last = segments[0][1];
        for (vector<int> &segment : segments) {
            if (last < segment[0]) {
                count++;
                last = segment[1];
            }
        }
        return count;
    }
};