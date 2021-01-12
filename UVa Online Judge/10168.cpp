#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    if (n < 8) {
        cout << "Impossible.\n";
        return 1;
    }

    vector<int> p = { 2, 2, 2, n - 6 };
    if (n % 2) {
        p[1]++;
        p[3]--;
    }

    while (!isPrime(p[2]) || !isPrime(p[3])) {
        p[2]++;
        p[3]--;
    }

    cout << p[0] << " " << p[1] << " " << p[2] << " " << p[3] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}