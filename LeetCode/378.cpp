class Solution {
    int countLess(vector<vector<int>> &a, int value) {
        int y = 0, x = a[0].size() - 1, res = 0;
        while (y < a.size() && x >= 0) {
            if (a[y][x] < value) {
                res += x + 1;
                y++;
            } else {
                x--;
            }
        }
        return res;
    }
    
public:
    int kthSmallest(vector<vector<int>> &a, int k) {
        int l = -1e9, r = 1e9 + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (countLess(a, m) < k)
                l = m;
            else
                r = m;
        }
        return l;
    }
};