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

void solve() {
    int size;
    cin >> size;

    int sum = 0, oddIndex = -1;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        sum += value;
        if (value % 2)
            oddIndex = i;
    }

    if (!isPrime(sum))
        oddIndex = -1;

    cout << size - (oddIndex != -1) << "\n";
    for (int i = 0; i < size; i++)
        if (i != oddIndex)
            cout << i + 1 << " ";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}