#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<bool> getIsPrime(int n) {
    vector<bool> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;

    for (long long i = 2; i <= n; i++)
        if (isPrime[i])
            for (long long j = i * i; j <= n; j += i)
                isPrime[j] = 0;

    return isPrime;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, queryCount;
    cin >> n >> queryCount;

    vector<bool> isPrime = getIsPrime(n);

    cout << count(isPrime.begin(), isPrime.end(), 1) << "\n";    
    for (int i = 0; i < queryCount; i++) {
        int x;
        cin >> x;
        cout << isPrime[x] << "\n";
    }
}