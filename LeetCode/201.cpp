class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        while (l < r)
            r &= r - 1;
        return r;
    }
};