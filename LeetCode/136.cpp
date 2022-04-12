class Solution {
public:
    int singleNumber(vector<int> &a) {
        int xorSum = 0;
        for (int value : a)
            xorSum ^= value;
        return xorSum;
    }
};