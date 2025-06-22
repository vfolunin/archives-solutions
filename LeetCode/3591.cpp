class Solution {
    bool isPrime(int n) {
        if (n < 2)
            return 0;
        
        for (long long d = 2; d * d <= n; d++)
            if (n % d == 0)
                return 0;
        
        return 1;
    }
    
public:
    bool checkPrimeFrequency(vector<int> &a) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;

        for (auto &[value, count] : count)
            if (isPrime(count))
                return 1;
        return 0;
    }
};