class Solution {
    int ones(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }
    
public:
    int minimizeXor(int a, int b) {
        int res = 0, count = ones(b);
        
        for (int bit = 30; bit >= 0; bit--) {
            if ((a & (1 << bit)) && count) {
                res |= 1 << bit;
                count--;
            }
        }
        
        for (int bit = 0; bit < 31; bit++) {
            if (!(a & (1 << bit)) && count) {
                res |= 1 << bit;
                count--;
            }
        }
        
        return res;
    }
};