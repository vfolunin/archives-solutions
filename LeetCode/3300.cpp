class Solution {
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minElement(vector<int> &a) {
        int res = 1e9;
        for (int value : a)
            res = min(res, digitSum(value));
        return res;
    }
};