class Solution {
    long long c(int n, int k) {
        if (n < k)
            return 0;

        static vector<vector<long long>> memo(30, vector<long long>(30, -1));
        long long &res = memo[n][k];
        if (res != -1)
            return res;

        if (k == 0 || k == n)
            return res = 1;

        return res = (c(n - 1, k) + c(n - 1, k - 1));
    }

public:
    string kthSmallestPath(vector<int> &destination, int k) {
        int h = destination[0], w = destination[1];
        string res;

        while (h || w) {
            long long count = c(h + w - 1, h);
            if (k <= count) {
                res += "H";
                w--;
            } else {
                k -= count;
                res += "V";
                h--;
            }
        }

        return res;
    }
};