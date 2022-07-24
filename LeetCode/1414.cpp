class Solution {
public:
    int findMinFibonacciNumbers(int n) {
        vector<int> fib = { 1, 1 };
        for (int i = 2; fib.back() < n; i++)
            fib.push_back(fib[i - 2] + fib[i - 1]);
        
        int res = 0;
        for (int i = fib.size() - 1; i; i--) {
            res += n / fib[i];
            n %= fib[i];
        }
        return res;
    }
};