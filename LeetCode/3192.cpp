class Solution {
public:
    int minOperations(vector<int> &a) {
        int res = 0, flip = 0;
        for (int value : a) {
            if (!(value ^ flip)) {
                res++;
                flip ^= 1;
            }
        }
        return res;
    }
};