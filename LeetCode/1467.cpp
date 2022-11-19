class Solution {
    double c(int n, int k) {
        static vector<vector<double>> memo(50, vector<double>(50, -1));
        double &res = memo[n][k];
        if (res != -1)
            return res;

        if (k == 0 || k == n)
            return res = 1;

        return res = c(n - 1, k) + c(n - 1, k - 1);
    }
    
    double rec(vector<int> &balls, int i, int aCount, int bCount, int aDistinct, int bDistinct, double ways) {
        if (i == balls.size())
            return aCount == bCount && aDistinct == bDistinct ? ways : 0;
        
        double res = 0;
        for (int a = 0, b = balls[i]; a <= balls[i]; a++, b--)
            res += rec(balls, i + 1, aCount + a, bCount + b, aDistinct + (a > 0), bDistinct + (b > 0), ways * c(balls[i], a));
        return res;
    }
    
public:
    double getProbability(vector<int> &balls) {
        double num = rec(balls, 0, 0, 0, 0, 0, 1);
        int sum = accumulate(balls.begin(), balls.end(), 0);
        double den = c(sum, sum / 2);
        return num / den;
    }
};