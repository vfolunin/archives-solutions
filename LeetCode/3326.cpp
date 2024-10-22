class Solution {
    int getMaxDivisor(int n) {
        for (int d = 2; d * d <= n; d++)
            if (n % d == 0)
                return n / d;
        return 1;
    }

public:
    int minOperations(vector<int> &a) {
        int res = 0;

        for (int i = (int)a.size() - 2; i >= 0; i--) {
            while (a[i] > a[i + 1]) {
                int d = getMaxDivisor(a[i]);
                if (d == 1)
                    return -1;
                
                a[i] /= d;
                res++;
            }
        }
        
        return res;
    }
};