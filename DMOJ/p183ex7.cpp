#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getIsPrime(int n) {
    vector<int> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i < isPrime.size(); i++) {
        if (isPrime[i])
            for (long long j = 1LL * i * i; j < isPrime.size(); j += i)
                isPrime[j] = 0;
    }

    return isPrime;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    vector<int> isPrime = getIsPrime(n);
    for (int i = 1; i < isPrime.size(); i++)
        cout << isPrime[i] << "\n";
}