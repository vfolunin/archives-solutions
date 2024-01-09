class Solution {
public:
    bool hasTrailingZeros(vector<int> &a) {
        int evenCount = 0;
        for (int &value : a)
            evenCount += value % 2 == 0;
        return evenCount > 1;
    }
};