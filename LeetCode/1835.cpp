class Solution {
    int xorSum(vector<int> &a) {
        int res = 0;
        for (int value : a)
            res ^= value;
        return res;
    }
    
public:
    int getXORSum(vector<int> &a, vector<int> &b) {
        return xorSum(a) & xorSum(b);
    }
};