class Solution {
    bool check(vector<vector<char>> &a, int y, int x) {
        int sum = 0;
        for (int dy = 0; dy < 2; dy++)
            for (int dx = 0; dx < 2; dx++)
                sum += a[y + dy][x + dx] == 'B';
        return sum != 2;
    }

public:
    bool canMakeSquare(vector<vector<char>> &a) {
        return check(a, 0, 0) || check(a, 0, 1) || check(a, 1, 0) || check(a, 1, 1);
    }
};