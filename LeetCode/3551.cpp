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
    int minSwaps(vector<int> &a) {
        vector<int> order(a.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int lhs, int rhs) {
            int lSum = digitSum(a[lhs]), rSum = digitSum(a[rhs]);
            if (lSum != rSum)
                return lSum < rSum;
            return a[lhs] < a[rhs];
        });

        int res = 0;
        vector<int> visited(order.size());
        for (int i = 0; i < order.size(); i++) {
            int cycleSize = 0;
            for (int j = i; !visited[j]; j = order[j]) {
                visited[j]++;
                cycleSize++;
            }
            res += max(cycleSize - 1, 0);
        }
        return res;
    }
};