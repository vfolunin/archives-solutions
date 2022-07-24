class Solution {
public:
    bool searchMatrix(vector<vector<int>> &a, int target) {
        int y = 0, x = a[0].size() - 1;
        while (y < a.size() && x >= 0) {
            if (a[y][x] == target)
                return 1;
            if (a[y][x] < target)
                y++;
            else
                x--;
        }
        return 0;
    }
};