class Solution {
public:
    int singleNonDuplicate(vector<int> &a) {
        int xorSum = 0;
        for (int value : a)
            xorSum ^= value;
        return xorSum;
    }
};