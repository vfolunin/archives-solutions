class Solution {
    int down(vector<vector<int>> &a, int y, int x) {
        if (y == a.size())
            return x;
        else if (a[y][x] == 1)
            return left(a, y, x + 1);
        else
            return right(a, y, x - 1);
    }
    
    int left(vector<vector<int>> &a, int y, int x) {
        if (x == a[0].size() || a[y][x] == -1)
            return -1;
        return down(a, y + 1, x);
    }
    
    int right(vector<vector<int>> &a, int y, int x) {
        if (x == -1 || a[y][x] == 1)
            return -1;
        return down(a, y + 1, x);
    }
    
public:
    vector<int> findBall(vector<vector<int>> &a) {
        vector<int> res(a[0].size());
        for (int x = 0; x < a[0].size(); x++)
            res[x] = down(a, 0, x);
        return res;
    }
};