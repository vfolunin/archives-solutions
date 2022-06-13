class Solution {
public:
    int peakIndexInMountainArray(vector<int> &a) {
        int l = 0, r = a.size() - 2;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (a[m] < a[m + 1])
                l = m;
            else
                r = m;
        }
        return r;
    }
};