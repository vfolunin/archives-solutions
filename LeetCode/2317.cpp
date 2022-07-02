class Solution {
public:
    int maximumXOR(vector<int> &a) {
        int res = 0;
        for (int value : a)
            res |= value;
        return res;
    }
};