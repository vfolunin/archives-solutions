#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(long long n) {
    if (n < 2)
        return 0;
    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int numberCount;
    cin >> numberCount;

    vector<int> primes;
    for (int i = 0; i < numberCount; i++) {
        int number;
        cin >> number;
        if (isPrime(number))
            primes.push_back(number);
    }

    sort(primes.begin(), primes.end());
    primes.erase(unique(primes.begin(), primes.end()), primes.end());

    cout << primes.size() << "\n";
    for (int i = 0; i < primes.size(); i++)
        cout << primes[i] << (i + 1 < primes.size() ? ", " : ".");
    cout << "\n";
}