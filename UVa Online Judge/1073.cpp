#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    long long n;
    cin >> n;

    if (!n)
        return 0;

    if (n % 2) {
        cout << "Case " << test << ": 0\n";
        return 1;
    }

    n /= 2;

    cout << "Case " << test << ": " << n * n * (n * n - 1) / 12 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}