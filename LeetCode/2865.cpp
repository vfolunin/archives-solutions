class Solution {
    long long getSum(vector<int> &a, int from) {
        long long sum = a[from];
        for (int i = from - 1, count = a[from]; i >= 0; i--) {
            count = min(count, a[i]);
            sum += count;
        }
        for (int i = from + 1, count = a[from]; i < a.size(); i++) {
            count = min(count, a[i]);
            sum += count;
        }
        return sum;
    }

public:
    long long maximumSumOfHeights(vector<int> &a) {
        long long res = 0;
        for (int i = 0; i < a.size(); i++)
            res = max(res, getSum(a, i));
        return res;
    }
};