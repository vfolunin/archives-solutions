class Solution {
public:
    int sumOfGoodIntegers(int n, int limit) {
        int res = 0;
        for (int i = max(n - limit, 0); i <= n + limit; i++)
            if (!(n & i))
                res += i;
        return res;
    }
};