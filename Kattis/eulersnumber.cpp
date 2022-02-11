#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    long double e = 1, f = 1;

    for (int i = 1; i <= n; i++) {
        f *= i;
        e += 1.0 / f;
    }

    cout.precision(15);
    cout << fixed << e;
}