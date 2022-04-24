class Solution {
public:
    int arraySign(vector<int> &a) {
        int sign = 1;
        for (int value : a) {
            if (!value)
                return 0;
            if (value < 0)
                sign = -sign;
        }
        return sign;
    }
};