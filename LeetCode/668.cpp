class Solution {
    bool can(int h, int w, int index, int value) {
        int count = 0;
        for (int y = 1; y <= h; y++)
            count += min(w, value / y);
        return count < index;
    }
    
public:
    int findKthNumber(int h, int w, int index) {
        int l = 0, r = 1e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(h, w, index, m))
                l = m;
            else
                r = m;
        }
        return r;
    }
};