class Solution {
public:
    bool areSimilar(vector<vector<int>> &a, int k) {
        int h = a.size(), w = a[0].size();

        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                if (y % 2 == 0 && a[y][x] != a[y][(x + k) % w] || y % 2 && a[y][x] != a[y][(x - k % w + w) % w])
                    return 0;
        
        return 1;
    }
};