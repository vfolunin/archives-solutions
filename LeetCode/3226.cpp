class Solution {
public:
    int minChanges(int a, int b) {
        int res = 0;
        for (int bit = 0; bit < 20; bit++) {
            if (!(a & (1 << bit)) && (b & (1 << bit)))
                return -1;
            if ((a & (1 << bit)) && !(b & (1 << bit)))
                res++;
        }
        return res;
    }
};