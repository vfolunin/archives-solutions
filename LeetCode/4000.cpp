class Solution {
public:
    int largestInteger(int size, int sum) {
        if (size * 9 < sum)
            return -1;

        int res = 0;
        while (sum) {
            int delta = min(9, sum);
            res = res * 10 + delta;
            sum -= delta;
            size--;
        }

        for (int i = 0; i < size; i++)
            res *= 10;
        return res;
    }
};