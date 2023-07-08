class Solution {
public:
    vector<long long> countBlackBlocks(int h, int w, vector<vector<int>> &cells) {
        map<pair<int, int>, int> cellMap;
        vector<int> dy = { 0, 0, -1, -1 };
        vector<int> dx = { 0, -1, 0, -1 };

        for (vector<int> &cell : cells) {
            for (int d = 0; d < dy.size(); d++) {
                int ty = cell[0] + dy[d];
                int tx = cell[1] + dx[d];
                if (0 <= ty && ty + 1 < h && 0 <= tx && tx + 1 < w)
                    cellMap[{ ty, tx }]++;
            }
        }
        
        vector<long long> res = { (h - 1LL) * (w - 1LL), 0, 0, 0, 0 };
        for (auto &[cell, count] : cellMap) {
            res[0]--;
            res[count]++;
        }        
        return res;
    }
};