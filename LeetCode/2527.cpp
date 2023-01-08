class Solution {
public:
    int xorBeauty(vector<int> &a) {
        int xorSum = 0;
        for (int value : a)
            xorSum ^= value;
        return xorSum;
    }
};