class Solution {
public:
    int findMin(vector<int> &a) {
        int l = 0, r = a.size() - 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (a[m] > a[r])
                l = m;
            else
                r = m;
        }
        return min(a[l], a[r]);
    }
};