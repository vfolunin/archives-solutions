class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box) {
        vector<vector<char>> res(box[0].size(), vector<char>(box.size()));
        
        for (int y = 0; y < res.size(); y++)
            for (int x = 0; x < res[0].size(); x++)
                res[y][x] = box[res[0].size() - 1 - x][y];
        
        for (int y = res.size() - 1; y >= 0; y--) {
            for (int x = 0; x < res[0].size(); x++) {
                if (res[y][x] == '#') {
                    int to = y;
                    while (to + 1 < res.size() && res[to + 1][x] == '.')
                        to++;                    
                    swap(res[y][x], res[to][x]);
                }
            }
        }
        
        return res;
    }
};