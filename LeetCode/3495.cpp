class Solution {
public:
    long long minOperations(vector<vector<int>> &queries) {
        long long res = 0;

        for (vector<int> &query : queries) {
            long long l = query[0], r = query[1] + 1;

            long long sum = 0;
            for (long long ops = 1, opL = 1, opR = 4; opL <= r; ops++, opL *= 4, opR *= 4)
                sum += max(ops * (min(r, opR) - max(l, opL)), 0LL);
                
            res += (sum + 1) / 2;
        }

        return res;
    }
};