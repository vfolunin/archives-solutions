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

    while (n) {
        int sum = n + 1;
        while (!isPrime(sum))
            sum++;

        for (int i = sum - n; i < sum - i; i++)
            cout << i << " " << sum - i << "\n";

        n = sum - n - 1;
    }
}