class Solution {
public:
    int findLongestChain(vector<vector<int>> &segments) {
        sort(segments.begin(), segments.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        
        int res = 0, to = -1e9;
        for (vector<int> &segment : segments) {
            if (to < segment[0]) {
                res++;
                to = segment[1];
            }
        }
        
        return res;
    }
};