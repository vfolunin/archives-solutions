class Solution {
public:
    string maxSumOfSquares(int count, int sum) {
        if (count * 9 < sum)
            return "";

        string res;
        while (sum) {
            int delta = min(sum, 9);
            res += delta + '0';
            sum -= delta;
        }

        res += string(count - res.size(), '0');
        return res;
    }
};