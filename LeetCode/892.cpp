class Solution {
public:
    int surfaceArea(vector<vector<int>> &a) {
        int size = a.size(), res = 0;
        
        for (int y = 0; y < size; y++) {
            res += a[y][0];
            for (int x = 1; x < size; x++)
                res += abs(a[y][x - 1] - a[y][x]);
            res += a[y][size - 1];
        }
        
        for (int x = 0; x < size; x++) {
            res += a[0][x];
            for (int y = 1; y < size; y++)
                res += abs(a[y - 1][x] - a[y][x]);
            res += a[size - 1][x];
        }
        
        for (int y = 0; y < size; y++)
            for (int x = 0; x < size; x++)
                if (a[y][x])
                    res += 2;
        
        return res;
    }
};