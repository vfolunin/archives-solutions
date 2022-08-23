class Solution {
    double rec(int a, int b) {
        if (a >= 1000 || b >= 1000)
            return 1;
        
        if (a < 0)
            a = 0;
        if (b < 0)
            b = 0;
        
        static vector<vector<double>> memo(1000, vector<double>(1000, -1));
        double &res = memo[a][b];
        if (res != -1)
            return res;
        
        if (!a && !b)
            return res = 0.5;
        if (!a)
            return res = 1;
        if (!b)
            return res = 0;
        
        return res = (rec(a - 4, b) + rec(a - 3, b - 1) + rec(a - 2, b - 2) + rec(a - 1, b - 3)) / 4;
    }
    
public:
    double soupServings(int n) {
        n = (n + 24) / 25;
        return rec(n, n);
    }
};