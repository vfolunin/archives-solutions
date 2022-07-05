class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        
        for (int bit = 0; bit < 30; bit++) {
            int aBit = (a >> bit) & 1;
            int bBit = (b >> bit) & 1;
            int cBit = (c >> bit) & 1;
            
            if (cBit)
                res += !aBit && !bBit;
            else
                res += aBit + bBit;
        }
        
        return res;
    }
};