#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
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

    int n;
    cin >> n;

    vector<int> fib = { 1, 1 }, res;
    for (int i = 2; res.size() < n; i++) {
        fib.push_back(fib[i - 2] + fib[i - 1]);
        if (isPrime(fib.back()))
            res.push_back(fib.back());
    }

    cout << res.back();
}