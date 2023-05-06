#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getPrimeSum(int n) {
    vector<int> isPrime(n + 1, 1);
    long long sum = 0;

    for (int i = 2; i < isPrime.size(); i++) {
        if (isPrime[i]) {
            sum += i;
            for (long long j = 1LL * i * i; j < isPrime.size(); j += i)
                isPrime[j] = 0;
        }
    }

    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << getPrimeSum(n);
}