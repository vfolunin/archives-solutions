class Solution {
public:
    int clumsy(int n) {
        int res = 0, i = n, sign = 1;
        
        for ( ; i >= 4; i -= 4, sign = -1)
            res += sign * i * (i - 1) / (i - 2) + (i - 3);
        
        if (i == 3)
            res += sign * i * (i - 1) / (i - 2);
        else if (i == 2)
            res += sign * i * (i - 1);
        else if (i == 1)
            res += sign * i;
        
        return res;
    }
};