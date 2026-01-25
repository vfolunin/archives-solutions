class Solution {
    long long c(int n, int k) {
        if (n < k)
            return 0;
            
        static vector<vector<long long>> memo(51, vector<long long>(51, -1));
        long long &res = memo[n][k];
        if (res != -1)
            return res;

        if (k == 0 || k == n)
            return res = 1;

        return res = c(n - 1, k) + c(n - 1, k - 1);
    }

public:
    long long nthSmallest(long long index, int ones) {
        index--;
        ones--;

        int size = ones;
        while (index >= c(size, ones)) {
            index -= c(size, ones);
            size++;
        }

        long long res = 1;
        for (int i = 0; i < size; i++) {
            res *= 2;
            if (index >= c(size - 1 - i, ones)) {
                index -= c(size - 1 - i, ones);
                ones--;
                res++;
            }
        }
        return res;
    }
};