class Solution {
public:
    bool threeFibonacciSum(int n) {
        vector<long long> fib = { 0, 1 };
        while (fib.back() <= n)
            fib.push_back(fib[fib.size() - 2] + fib[fib.size() - 1]);

        for (int i = 0; i + 2 < fib.size(); i++)
            if (fib[i] + fib[i + 1] + fib[i + 2] == n)
                return 1;
        return 0;
    }
};