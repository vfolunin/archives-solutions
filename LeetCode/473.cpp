class Solution {
public:
    bool makesquare(vector<int> &a) {
        int side = 0;
        for (int value : a)
            side += value;
        if (side % 4)
            return 0;
        side /= 4;
        
        unordered_set<int> sideMasks, halfMasks;
        
        for (int mask = 0; mask < (1 << a.size()); mask++) {
            int sum = 0;
            for (int bit = 0; bit < a.size(); bit++)
                if (mask & (1 << bit))
                    sum += a[bit];
            
            if (sum == side)
                sideMasks.insert(mask);
            if (sum == side * 2)
                halfMasks.insert(mask);
        }
        
        unordered_set<int> goodHalfMasks;
        
        for (int halfMask : halfMasks) {
            for (int sideMask : sideMasks) {
                if ((halfMask & sideMask) == sideMask && sideMasks.count(halfMask ^ sideMask)) {
                    goodHalfMasks.insert(halfMask);
                    break;
                }
            }
        }
        
        for (int halfMask : goodHalfMasks)
            if (goodHalfMasks.count(((1 << a.size()) - 1) ^ halfMask))
                return 1;
                
        return 0;
    }
};