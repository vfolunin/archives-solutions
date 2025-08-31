class Solution {
public:
    long long maxProduct(vector<int> &a) {
        int maxValue = *max_element(a.begin(), a.end());
        int maskSize = 0;
        while ((1 << maskSize) <= maxValue)
            maskSize++;

        vector<int> maxMaskValue(1 << maskSize);
        for (int value : a)
            maxMaskValue[value] = value;

        for (int mask = 0; mask < (1 << maskSize); mask++)
            for (int bit = 0; bit < maskSize; bit++)
                if (mask & (1 << bit))
                    maxMaskValue[mask] = max(maxMaskValue[mask], maxMaskValue[mask - (1 << bit)]);
        
        long long res = 0;
        for (int value : a)
            res = max(res, 1LL * value * maxMaskValue[(1 << maskSize) - 1 - value]);
        return res;
    }
};