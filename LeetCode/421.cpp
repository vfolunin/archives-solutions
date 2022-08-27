class Solution {
public:
    int findMaximumXOR(vector<int> &a) {
        int res = 0;
        
        for (int bit = 30, mask = 0; bit >= 0; bit--) {
            mask |= 1 << bit;
            
            set<int> prefixes;
            for (int value : a)
                prefixes.insert(value & mask);
            
            for (int prefix : prefixes) {
                if (prefixes.count(res ^ prefix ^ (1 << bit))) {
                    res |= 1 << bit;
                    break;
                }
            }
        }
        
        return res;
    }
};