class Solution {
public:
    int distributeCandies(int n, int limit) {
        int res = 0;
        for (int a = 0; a <= limit && a <= n; a++)
            for (int b = 0; b <= limit && a + b <= n; b++)
                res += n - a - b <= limit;
        return res;
    }
};