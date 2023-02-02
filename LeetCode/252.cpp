class Solution {
public:
    bool canAttendMeetings(vector<vector<int>> &segments) {
        sort(segments.begin(), segments.end());
        for (int i = 0; i + 1 < segments.size(); i++)
            if (segments[i][1] > segments[i + 1][0])
                return 0;
        return 1;
    }
};