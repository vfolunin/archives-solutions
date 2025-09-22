class Solution {
public:
    int evenNumberBitwiseORs(vector<int> &a) {
        int res = 0;
        for (int value : a)
            if (value % 2 == 0)
                res |= value;
        return res;
    }
};