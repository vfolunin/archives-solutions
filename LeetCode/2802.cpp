class Solution {
public:
    string kthLuckyNumber(int index) {
        long long count = 2;
        for (index--; index >= count; count *= 2)
            index -= count;

        string res;
        for (count /= 2; count; count /= 2) {
            res += (index / count) ? '7' : '4';
            index %= count;
        }
        return res;
    }
};