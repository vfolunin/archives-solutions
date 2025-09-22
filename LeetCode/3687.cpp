class Solution {
public:
    int lateFee(vector<int> &a) {
        int res = 0;
        for (int value : a) {
            if (value == 1)
                res++;
            else if (value <= 5)
                res += 2 * value;
            else
                res += 3 * value;
        }
        return res;
    }
};