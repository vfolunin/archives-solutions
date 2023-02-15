class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int l = 0, r = reader.length() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if ((r - l + 1) % 2) {
                int ans = reader.compareSub(l, m - 1, m + 1, r);
                if (ans == 0)
                    return m;
                else if (ans < 0)
                    l = m + 1;
                else
                    r = m - 1;
            } else {
                if (reader.compareSub(l, m, m + 1, r) < 0)
                    l = m + 1;
                else
                    r = m;
            }
        }
        return l;
    }
};