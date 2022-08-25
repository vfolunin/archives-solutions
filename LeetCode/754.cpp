class Solution {
public:
    int reachNumber(int n) {
        n = abs(n);
        
        int res = 0;
        
        for (int jump = 1; n > 0; jump++) {
            n -= jump;
            res++;
        }
        
        if (n % 2)
            res += (res % 2 ? 2 : 1);
        
        return res;
    }
};