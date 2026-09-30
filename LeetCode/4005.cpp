class Solution {
    vector<int> getPrimes(int n) {
        vector<int> isPrime(n + 1, 1), primes;

        for (int i = 2; i < isPrime.size(); i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (long long j = 1LL * i * i; j < isPrime.size(); j += i)
                    isPrime[j] = 0;
            }
        }

        return primes;
    }

    map<int, int> factorize(int n) {
        map<int, int> factorization;

        static vector<int> primes = getPrimes(4e4);
        for (int d : primes) {
            if (1LL * d * d > n)
                break;

            while (n % d == 0) {
                factorization[d]++;
                n /= d;
            }
        }
        if (n != 1)
            factorization[n]++;

        return factorization;
    }

    void rec(map<int, int> &factorization, map<int, int>::iterator it, int divisor, vector<int> &divisors) {
        if (it == factorization.end()) {
            divisors.push_back(divisor);
            return;
        }

        long long factor = 1;
        rec(factorization, next(it), divisor * factor, divisors);
        for (int i = 0; i < it->second; i++) {
            factor *= it->first;
            rec(factorization, next(it), divisor * factor, divisors);
        }
    }

    vector<int> getDivisors(int n) {
        map<int, int> factorization = factorize(n);
        vector<int> divisors;
        rec(factorization, factorization.begin(), 1, divisors);
        return divisors;
    }

public:
    long long minOperations(vector<int> &a) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;

        if (count.size() == 1)
            return 0;

        vector<pair<int, int>> pairs(count.begin(), count.end());
        unordered_map<int, int> index;
        for (int i = 0; i < pairs.size(); i++)
            index[pairs[i].first] = i;

        vector<int> divisorCount(pairs.size());
        vector<int> multipleCount(pairs.size());

        for (int i = 0; i < pairs.size(); i++) {
            for (int divisor : getDivisors(pairs[i].first)) {
                if (auto it = index.find(divisor); it != index.end()) {
                    int j = it->second;

                    divisorCount[i] += pairs[j].second;
                    multipleCount[j] += pairs[i].second;
                }
            }
        }

        int res = a.size();
        for (int i = 0; i < pairs.size(); i++)
            if (pairs[i].first != 1)
                res = min(res, 2 * (int)a.size() - divisorCount[i] - multipleCount[i]);
        return res;
    }
};