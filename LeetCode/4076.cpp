class Solution {
public:
    int resilientSubarray(vector<int> &a, int divisor) {
        int blockValue = a[0] % divisor, blockSize = 1, res = 1;
        
        for (int i = 1; i < a.size(); i++) {
            if (blockValue == a[i] % divisor) {
                blockSize++;
            } else {
                while (blockSize && blockValue * (blockSize - 1LL) % divisor)
                    blockSize--;
                res = max(res, blockSize);
                
                blockValue = a[i] % divisor;
                blockSize = 1;
            }
        }
        
        while (blockSize && blockValue * (blockSize - 1LL) % divisor)
            blockSize--;
        res = max(res, blockSize);

        return res;
    }
};