class Solution {
public:
    long long minimumMoney(vector<vector<int>> &transactions) {
        sort(transactions.begin(), transactions.end(), [](auto &a, auto &b) {
            int da = a[1] - a[0], db = b[1] - b[0];
            if ((da > 0) != (db > 0))
                return da <= 0;
            if (da <= 0)
                return a[1] < b[1];
            else
                return a[0] > b[0];
        });
        
        long long sum = 0, minSum = 0;
        for (vector<int> &transaction : transactions) {
            sum -= transaction[0];
            minSum = min(minSum, sum);
            sum += transaction[1];
        }
        
        return -minSum;
    }
};