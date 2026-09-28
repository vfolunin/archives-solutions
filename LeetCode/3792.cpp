class Solution {
public:
    int sumOfBlocks(int blockCount) {
        const long long MOD = 1e9 + 7;
        long long res = 0;
        for (int block = 1, value = 1; block <= blockCount; block++) {
            long long blockProduct = 1;
            for (int i = 0; i < block; i++, value++)
                blockProduct = blockProduct * value % MOD;
            res = (res + blockProduct) % MOD;
        }
        return res;
    }
};