class Solution {
    bool checkMask(int h, int mask) {
        for (int i = 0; i + 1 < h; i++) {
            if (mask % 3 == mask / 3 % 3)
                return 0;
            mask /= 3;
        }
        return 1;
    }
    
    bool checkTransition(int h, int maskA, int maskB) {
        for (int i = 0; i < h; i++) {
            if (maskA % 3 == maskB % 3)
                return 0;
            maskA /= 3;
            maskB /= 3;
        }
        return 1;
    }
    
public:
    int colorTheGrid(int h, int w) {
        int maskCount = 1;
        for (int i = 0; i < h; i++)
            maskCount *= 3;
        
        vector<int> validMask(maskCount);
        for (int mask = 0; mask < maskCount; mask++)
            validMask[mask] = checkMask(h, mask);
        
        vector<vector<int>> validTransition(maskCount, vector<int>(maskCount));
        for (int maskA = 0; maskA < maskCount; maskA++)
            for (int maskB = 0; maskB < maskCount; maskB++)
                validTransition[maskA][maskB] = validMask[maskA] && validMask[maskB] && checkTransition(h, maskA, maskB);
        
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> count(w, vector<long long>(maskCount));
        
        for (int mask = 0; mask < maskCount; mask++)
            count[0][mask] = validMask[mask];
        
        for (int i = 1; i < w; i++)
            for (int mask = 0; mask < maskCount; mask++)
                for (int prevMask = 0; prevMask < maskCount; prevMask++)
                    if (validTransition[prevMask][mask])
                        count[i][mask] = (count[i][mask] + count[i - 1][prevMask]) % MOD;
        
        long long res = 0;
        for (int mask = 0; mask < maskCount; mask++)
            res = (res + count[w - 1][mask]) % MOD;
        return res;
    }
};