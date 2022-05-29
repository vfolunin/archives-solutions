class Solution {
public:
    void rotate(vector<vector<int>> &a) {
        int size = a.size();
        for (int y = 0; y < size / 2; y++) {
            for (int x = 0; x * 2 < size; x++) {
                swap(a[y][x], a[size - 1 - x][y]);
                swap(a[size - 1 - x][y], a[size - 1 - y][size - 1 - x]);
                swap(a[size - 1 - y][size - 1 - x], a[x][size - 1 - y]);
            }
        }
    }
};