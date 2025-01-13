class Solution {
    long long process(vector<vector<int>> &segments, int count) {
        long long cur = 0, res = 0;

        for (int l = 0, r = 0; l < segments.size(); l++) {
            while (r < segments.size() && segments[l][0] + count > segments[r][1]) {
                cur += (segments[r][1] - segments[r][0] + 1LL) * segments[r][2];
                r++;
            }
            
            long long add = 0;
            if (r < segments.size() && segments[l][0] + count > segments[r][0])
                add = 1LL * (segments[l][0] + count - segments[r][0]) * segments[r][2];

            res = max(res, cur + add);

            cur -= (segments[l][1] - segments[l][0] + 1LL) * segments[l][2];
        }

        return res;
    }

public:
    long long maximumCoins(vector<vector<int>> &segments, int count) {
        sort(segments.begin(), segments.end());
        long long res = process(segments, count);

        reverse(segments.begin(), segments.end());
        for (vector<int> &segment : segments)
            segment = { -segment[1], -segment[0], segment[2] };
        res = max(res, process(segments, count));

        return res;
    }
};