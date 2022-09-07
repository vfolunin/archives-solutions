class Solution {
public:
    int cherryPickup(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> bonus(w, vector<int>(w, -1e9));
        bonus[0][w - 1] = a[0][0] + a[0][w - 1];
        
        for (int y = 1; y < h; y++) {
            vector<vector<int>> nextBonus(w, vector<int>(w, -1e9));
            
            for (int xa = 0; xa < w; xa++) {
                for (int nxa : { xa - 1, xa, xa + 1 }) {
                    if (nxa < 0 || nxa >= w)
                        continue;
                    
                    for (int xb = 0; xb < w; xb++) {
                        for (int nxb : { xb - 1, xb, xb + 1 }) {
                            if (nxb < 0 || nxb >= w)
                                continue;
                            
                            nextBonus[nxa][nxb] = max(nextBonus[nxa][nxb],
                                                      bonus[xa][xb] + a[y][nxa] + (nxa == nxb ? 0 : a[y][nxb]));
                        }
                    }
                }
            }
            
            bonus.swap(nextBonus);
        }
        
        int res = 0;
        for (int xa = 0; xa < w; xa++)
            for (int xb = 0; xb < w; xb++)
                res = max(res, bonus[xa][xb]);
        return res;
    }
};