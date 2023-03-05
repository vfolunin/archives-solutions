#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getIsPrime(int n) {
    vector<int> isPrime(n + 1, 1);

    for (int i = 2; i < isPrime.size(); i++)
        if (isPrime[i])
            for (long long j = 1LL * i * i; j < isPrime.size(); j += i)
                isPrime[j] = 0;

    return isPrime;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    vector<int> isPrime = getIsPrime(r * 2 + 1);

    bool found = 0;
    for (int i = l; i <= r; i++) {
        if (isPrime[i] && isPrime[i * 2 + 1]) {
            cout << i << " ";
            found = 1;
        }
    }

    if (!found)
        cout << 0;
}