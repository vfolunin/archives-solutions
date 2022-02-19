#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getDivisorSum(int n) {
    int sum = 1;
    for (long long d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            sum += d;
            if (d * d != n)
                sum += n / d;
        }
    }
    return sum;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    int divisorSum = getDivisorSum(n);

    cout << n << " ";
    if (n == divisorSum)
        cout << "perfect\n";
    else if (abs(n - divisorSum) <= 2)
        cout << "almost perfect\n";
    else
        cout << "not perfect\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}