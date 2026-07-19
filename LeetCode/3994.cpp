class Solution {
    long long mergeSort(vector<int> &a, vector<int> &t, int l, int r) {
        if (l == r)
            return 0;

        int m = l + (r - l) / 2;
        long long inversionCount = 0;
        inversionCount += mergeSort(a, t, l, m);
        inversionCount += mergeSort(a, t, m + 1, r);

        for (int i = l; i <= r; i++)
            t[i] = a[i];

        int ai = l, bi = m + 1;
        for (int i = l; i <= r; i++) {
            if (bi > r || ai <= m && t[ai] <= t[bi]) {
                a[i] = t[ai++];
            } else {
                inversionCount += m - ai + 1;
                a[i] = t[bi++];
            }
        }

        return inversionCount;
    }

public:
    int minAdjacentSwaps(vector<int> &a, int lValue, int rValue) {
        for (int &value : a) {
            if (value < lValue)
                value = -1;
            else if (value <= rValue)
                value = 0;
            else
                value = 1;
        }

        vector<int> t(a.size());
        return mergeSort(a, t, 0, a.size() - 1) % (int)(1e9 + 7);
    }
};