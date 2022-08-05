class Solution {
public:
    long long zeroFilledSubarray(vector<int> &a) {
        long long res = 0;
        int row = 0;
        for (int value : a) {
            if (value)
                row = 0;
            else
                row++;
            res += row;
        }
        return res;
    }
};