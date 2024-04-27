#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int targetSum, targetCount;
    cin >> targetSum >> targetCount;

    vector<int> primes = getPrimes(targetSum);
    vector<vector<long long>> ways(targetCount + 1, vector<long long>(targetSum + 1));
    ways[0][0] = 1;

    for (int count = 1; count < ways.size(); count++)
        for (int sum = 0; sum < ways[count].size(); sum++)
            for (int p : primes)
                if (sum >= p)
                    ways[count][sum] += ways[count - 1][sum - p];
    
    cout << (ways[targetCount][targetSum] ? ways[targetCount][targetSum] : -1);
}