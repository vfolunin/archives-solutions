class Solution {
public:
    int findClosestNumber(vector<int> &a) {
        int res = a[0];
        for (int value : a)
            if (abs(res) > abs(value) || abs(res) == abs(value) && res < value)
                res = value;
        return res;
    }
};