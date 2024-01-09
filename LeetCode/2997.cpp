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
    int minOperations(vector<int> &a, int target) {
        int xorSum = 0;
        for (int value : a)
            xorSum ^= value;
        return ones(xorSum ^ target);
    }
};