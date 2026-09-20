class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>> &segments) {
        sort(segments.begin(), segments.end());

        long long res = 0;
        for (int i = 0; i < segments.size(); i++) {
            int j = lower_bound(segments.begin(), segments.end(), vector<int>{ segments[i][1] + 1, 0 }) - segments.begin();
            res += j - i - 1;
        }
        return res;
    }
};