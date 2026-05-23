class Solution {
public:
    int minOperations(vector<int> &a, int divisor) {
        vector<vector<int>> modCount(2, vector<int>(divisor));
        for (int i = 0; i < a.size(); i++)
            modCount[i % 2][a[i] % divisor]++;
        
        vector<vector<int>> minOps(modCount.size(), vector<int>(divisor, 1e9));
        for (int i = 0; i < minOps.size(); i++) {
            for (int targetMod = 0; targetMod < divisor; targetMod++) {
                int ops = 0;
                for (int mod = 0; mod < divisor; mod++) {
                    int diff = abs(mod - targetMod);
                    diff = min(diff, divisor - diff);
                    ops += modCount[i % 2][mod] * diff;
                }
                minOps[i % 2][targetMod] = min(minOps[i % 2][targetMod], ops);
            }
        }

        int res = 1e9;
        for (int mod0 = 0; mod0 < divisor; mod0++)
            for (int mod1 = 0; mod1 < divisor; mod1++)
                if (mod0 != mod1)
                    res = min(res, minOps[0][mod0] + minOps[1][mod1]);
        return res;
    }
};