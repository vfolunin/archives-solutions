class Solution {
public:
    int hIndex(vector<int> &a) {
        int l = 0, r = a.size() + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (a[a.size() - m] >= m)
                l = m;
            else
                r = m;
        }
        return l;
    }
};