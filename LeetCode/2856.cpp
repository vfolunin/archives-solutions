class Solution {
    bool can(vector<int> &a, int width) {
        for (int i = 0; i < width; i++)
            if (a[i] >= a[a.size() - width + i])
                return 0;
        return 1;
    }

public:
    int minLengthAfterRemovals(vector<int> &a) {
        int l = 0, r = a.size() / 2 + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, m))
                l = m;
            else
                r = m;
        }
        return a.size() - 2 * l;
    }
};