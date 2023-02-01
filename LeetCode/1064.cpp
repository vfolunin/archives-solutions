class Solution {
public:
    int fixedPoint(vector<int> &a) {
        int l = -1, r = a.size();
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (a[m] < m)
                l = m;
            else
                r = m;
        }
        return r != a.size() && a[r] == r ? r : -1;
    }
};