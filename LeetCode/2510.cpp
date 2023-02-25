class Solution {
public:
    bool isThereAPath(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        if ((h + w) % 2 == 0)
            return 0;
            
        vector<vector<vector<int>>> can(h, vector<vector<int>>(w, vector<int>((h + w) / 2 + 1)));
        can[0][0][a[0][0]] = 1;

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                for (int sum = 0; sum <= (h + w) / 2; sum++) {
                    can[y][x][sum] |= y && sum >= a[y][x] && can[y - 1][x][sum - a[y][x]];
                    can[y][x][sum] |= x && sum >= a[y][x] && can[y][x - 1][sum - a[y][x]];
                }
            }
        }

        return can[h - 1][w - 1][(h + w) / 2];
    }
};