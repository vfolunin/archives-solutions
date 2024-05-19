class Solution {
    long long c(int n, int k) {
        static vector<vector<long long>> memo(32, vector<long long>(32, -1));
        long long &res = memo[n][k];
        if (res != -1)
            return res;

        if (k == 0 || k == n)
            return res = 1;

        return res = c(n - 1, k) + c(n - 1, k - 1);
    }

public:
    int waysToReachStair(int n) {
        int res = 0;
        for (int count2 = 0; count2 < 31; count2++) {
            int count1 = (1 << count2) - n;
            if (0 <= count1 && count1 <= count2 + 1)
                res += c(count2 + 1, count1);
        }
        return res;
    }
};