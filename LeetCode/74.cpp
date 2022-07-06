class Solution {
public:
    bool searchMatrix(vector<vector<int>> &a, int target) {
        int h = a.size(), w = a[0].size();
        int l = 0, r = h * w - 1;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (a[m / w][m % w] == target)
                return 1;
            if (a[m / w][m % w] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        
        return 0;
    }
};