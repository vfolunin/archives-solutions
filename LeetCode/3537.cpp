class Solution {
    void rec(vector<vector<int>> &a, int p, int y, int x, int &counter) {
        if (!p) {
            a[y][x] = counter++;
            return;
        }
        int half = 1 << (p - 1);
        rec(a, p - 1, y, x + half, counter);
        rec(a, p - 1, y + half, x + half, counter);
        rec(a, p - 1, y + half, x, counter);
        rec(a, p - 1, y, x, counter);
    }

public:
    vector<vector<int>> specialGrid(int p) {
        vector<vector<int>> a(1 << p, vector<int>(1 << p));
        int counter = 0;
        rec(a, p, 0, 0, counter);
        return a;
    }
};