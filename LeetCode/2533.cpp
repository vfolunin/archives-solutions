class Solution {
public:
    int goodBinaryStrings(int minSize, int maxSize, int size1, int size0) {
        const long long MOD = 1e9 + 7;

        vector<long long> ways(maxSize + 1);
        ways[0] = 1;

        for (int size = 1; size <= maxSize; size++) {
            if (size >= size0)
                ways[size] = (ways[size] + ways[size - size0]) % MOD;
            if (size >= size1)
                ways[size] = (ways[size] + ways[size - size1]) % MOD;
        }

        long long res = 0;
        for (int size = minSize; size <= maxSize; size++)
            res = (res + ways[size]) % MOD;
        return res;
    }
};