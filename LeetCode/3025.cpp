class Solution {
public:
    int numberOfPairs(vector<vector<int>> &points) {
        int res = 0;

        for (int a = 0; a < points.size(); a++) {
            for (int b = 0; b < points.size(); b++) {
                if (a == b || points[a][0] > points[b][0] || points[a][1] < points[b][1])
                    continue;

                bool ok = 1;
                for (int c = 0; c < points.size() && ok; c++)
                    ok &= c == a || c == b ||
                          points[c][0] < points[a][0] || points[b][0] < points[c][0] ||
                          points[c][1] < points[b][1] || points[a][1] < points[c][1];
                
                res += ok;
            }
        }

        return res;
    }
};