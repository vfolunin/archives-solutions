class Solution {
    int ones(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }

public:
    int sumIndicesWithKSetBits(vector<int> &a, int oneCount) {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            if (ones(i) == oneCount)
                res += a[i];
        return res;
    }
};