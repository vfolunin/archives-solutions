class Solution {
public:
    vector<int> getMaximumXor(vector<int> &a, int p) {
        int xorSum = 0;
        for (int value : a)
            xorSum ^= value;
        
        int maxMask = (1 << p) - 1;
        vector<int> res = { maxMask - xorSum };
        
        for (int i = a.size() - 1; i; i--) {
            xorSum ^= a[i];
            res.push_back(maxMask - xorSum);
        }
        
        return res;
    }
};