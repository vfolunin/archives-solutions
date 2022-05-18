class Solution {
public:
    int subsetXORSum(vector<int> &a) {
        int res = 0;
        
        for (int mask = 0; mask < (1 << a.size()); mask++) {
            int subsetXor = 0;
            
            for (int bit = 0; bit < a.size(); bit++)
                if (mask & (1 << bit))
                    subsetXor ^= a[bit];
            
            res += subsetXor;
        }
        
        return res;
    }
};