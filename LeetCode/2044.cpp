class Solution {
public:
    int countMaxOrSubsets(vector<int> &a) {
        int maxOrSum = 0;
        for (int value : a)
            maxOrSum |= value;
        
        int res = 0;
        
        for (int mask = 0; mask < (1 << a.size()); mask++) {
            int orSum = 0;
            for (int bit = 0; bit < a.size(); bit++)
                if (mask & (1 << bit))
                    orSum |= a[bit];
            res += orSum == maxOrSum;
        }
        
        return res;
    }
};