class Solution {
    int rec(int a, int b, unordered_map<int, int> &memo) {
        int &res = memo[b];
        if (res)
            return res;

        if (a > b)
            return res = min(b * 2 - 1, (a - b) * 2);

        long long product = a;
        int ops = 0;
        while (product * a <= b) {
            product *= a;
            ops++;
        }

        if (product == b)
            return ops;

        int res1 = ops + 1 + rec(a, b - product, memo);

        product *= a;
        ops++;

        int res2 = 1e9;
        if (product - b < b)
            res2 = ops + 1 + rec(a, product - b, memo);

        return res = min(res1, res2);
    }
    
public:
    int leastOpsExpressTarget(int a, int b) {
        unordered_map<int, int> memo;
        return rec(a, b, memo);
    }
};