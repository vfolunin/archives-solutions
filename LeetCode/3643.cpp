class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>> &a, int startY, int startX, int size) {
        for (int y = 0; y * 2 < size; y++)
            for (int x = 0; x < size; x++)
                swap(a[startY + y][startX + x], a[startY + size - 1 - y][startX + x]);
        return a;
    }
};