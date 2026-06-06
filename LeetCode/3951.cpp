class Solution {
public:
    long long minEnergy(int size, int threshold, vector<vector<int>> &segments) {
        sort(segments.begin(), segments.end());

        int l = segments[0][0], r = segments[0][1], totalTime = 0;
        for (int i = 1; i < segments.size(); i++) {
            if (segments[i][0] <= r) {
                r = max(r, segments[i][1]);
            } else {
                totalTime += r - l + 1;
                l = segments[i][0];
                r = segments[i][1];
            }
        }
        totalTime += r - l + 1;

        return (threshold + 2LL) / 3 * totalTime;
    }
};