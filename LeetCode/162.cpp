class Solution {
public:
    int findPeakElement(vector<int> &a) {
        int l = 0, r = a.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (a[m] < a[m + 1])
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};