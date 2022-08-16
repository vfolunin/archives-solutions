class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &a, int k) {
        int h = a.size(), w = a[0].size();
        vector<vector<int>> rings;
        
        for (int ri = 0; ri * 2 < h && ri * 2 < w; ri++) {
            auto &ring = rings.emplace_back();
            int y = ri, x = ri;
            
            for (int i = 0; i < w - 2 * ri - 1; i++) 
                ring.push_back(a[y][x++]);
            for (int i = 0; i < h - 2 * ri - 1; i++) 
                ring.push_back(a[y++][x]);
            for (int i = 0; i < w - 2 * ri - 1; i++) 
                ring.push_back(a[y][x--]);
            for (int i = 0; i < h - 2 * ri - 1; i++) 
                ring.push_back(a[y--][x]);
            
            rotate(ring.begin(), ring.begin() + k % ring.size(), ring.end());
        }
        
        for (int ri = 0; ri * 2 < h && ri * 2 < w; ri++) {
            auto &ring = rings[ri];
            int y = ri, x = ri, rj = 0;
            
            for (int i = 0; i < w - 2 * ri - 1; i++)
                a[y][x++] = ring[rj++];
            for (int i = 0; i < h - 2 * ri - 1; i++)
                a[y++][x] = ring[rj++];
            for (int i = 0; i < w - 2 * ri - 1; i++)
                a[y][x--] = ring[rj++];
            for (int i = 0; i < h - 2 * ri - 1; i++)
                a[y--][x] = ring[rj++];
        }
        
        return a;
    }
};