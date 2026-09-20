class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>> &segments) {
        int res = 0;
        for (int i = 0; i < segments.size(); i++)
            for (int  j = i + 1; j < segments.size(); j++)
                res += segments[i][0] <= segments[j][1] && segments[j][0] <= segments[i][1];
        return res;
    }
};