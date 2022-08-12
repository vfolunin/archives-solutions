class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> u(h, vector<int>(w));
        vector<vector<int>> l(h, vector<int>(w));
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (a[y][x]) {
                    u[y][x] = 1 + (y ? u[y - 1][x] : 0);
                    l[y][x] = 1 + (x ? l[y][x - 1] : 0);
                }
            }
        }
        
        for (int size = min(h, w); size; size--)
            for (int y1 = 0, y2 = size - 1; y2 < h; y1++, y2++)
                for (int x1 = 0, x2 = size - 1; x2 < w; x1++, x2++)
                    if (u[y2][x1] >= size && u[y2][x2] >= size &&
                        l[y1][x2] >= size && l[y2][x2] >= size)
                        return size * size;
        return 0;
    }
};