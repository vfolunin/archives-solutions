class Solution {
public:
    bool checkXMatrix(vector<vector<int>> &a) {
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a.size(); x++)
                if ((y == x || y + x == a.size() - 1) ^ (a[y][x] != 0))
                    return 0;
        return 1;
    }
};