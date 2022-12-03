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

    vector<int> winner(n + 1, 2);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 3 && j <= i; j++)
            if (!isPrime(i - j) && winner[i - j] == 2)
                winner[i] = 1;

    cout << winner[n];
}