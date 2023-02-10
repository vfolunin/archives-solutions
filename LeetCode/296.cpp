class Solution {
public:
    int minTotalDistance(vector<vector<int>> &a) {
        vector<int> ys, xs;
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                if (a[y][x]) {
                    ys.push_back(y);
                    xs.push_back(x);
                }
            }
        }

        int res = 0;

        sort(ys.begin(), ys.end());
        for (int y : ys)
            res += abs(y - ys[ys.size() / 2]);

        sort(xs.begin(), xs.end());
        for (int x : xs)
            res += abs(x - xs[xs.size() / 2]);
        
        return res;
    }
};