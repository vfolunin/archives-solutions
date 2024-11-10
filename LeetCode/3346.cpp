class Solution {
public:
    int maxFrequency(vector<int> &a, int delta, int opCount) {
        sort(a.begin(), a.end());

        int res = 0;
        for (int value = 1, l = 0, le = 0, re = 0, r = 0; value <= 1e5; value++) {
            while (l < a.size() && a[l] < value - delta)
                l++;
            while (le < a.size() && a[le] < value)
                le++;
            while (re < a.size() && a[re] <= value)
                re++;
            while (r < a.size() && a[r] <= value + delta)
                r++;

            int equalCount = re - le;
            int changedCount = min(r - l - equalCount, opCount);
            res = max(res, equalCount + changedCount);
        }
        return res;
    }
};