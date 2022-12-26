class Solution {
public:
    int captureForts(vector<int> &a) {
        int res = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] != 1)
                continue;

            int l = 1;
            while (0 <= i - l && a[i - l] == 0)
                l++;
            if (0 <= i - l && a[i - l] == -1)
                res = max(res, l - 1);

            int r = 1;
            while (i + r < a.size() && a[i + r] == 0)
                r++;
            if (i + r < a.size() && a[i + r] == -1)
                res = max(res, r - 1);
        }

        return res;
    }
};