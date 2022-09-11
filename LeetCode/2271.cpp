class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>> &tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        
        vector<int> p(tiles.size());
        for (int i = 0; i < tiles.size(); i++) {
            p[i] = tiles[i][1] - tiles[i][0] + 1;
            if (i)
                p[i] += p[i - 1];
        }
        
        int res = 0;
        
        for (int i = 0; i < tiles.size(); i++) {
            int l = i, r = tiles.size();
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (tiles[i][0] + carpetLen > tiles[m][0])
                    l = m;
                else
                    r = m;
            }
            
            int fullyCovered = (l ? p[l - 1] : 0) - (i ? p[i - 1] : 0);
            int partlyCovered = min(tiles[i][0] + carpetLen - 1, tiles[l][1]) - tiles[l][0] + 1;
            res = max(res, fullyCovered + partlyCovered);
        }
        
        return res;
    }
};