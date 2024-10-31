class Solution {
public:
    int minOrAfterOperations(vector<int> &a, int limit) {
        int removedMask = 0;
        
        for (int bit = 29; bit >= 0; bit--) {
            removedMask |= 1 << bit;
            int andSum = removedMask & a[0], ops = 0;
            
            for (int i = 1; i < a.size(); i++) {
                if (andSum) {
                    andSum &= a[i];
                    ops++;
                } else {
                    andSum = removedMask & a[i];
                }
            }
            
            if (andSum)
                ops++;
            if (ops > limit)
                removedMask ^= 1 << bit;
        }
        
        return (1 << 30) - 1 - removedMask;
    }
};