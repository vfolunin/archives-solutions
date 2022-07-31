class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>> &segments, int n) {
        vector<int> p(n + 1);
        for (vector<int> &segment : segments) {
            p[segment[0] - 1] += segment[2];
            p[segment[1]] -= segment[2];
        }
        
        partial_sum(p.begin(), p.end(), p.begin());
        p.pop_back();
        return p;
    }
};