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

    cout << n << ":\n";
    for (int a = 2; a < n; a++) {
        if (n % (2 * a - 1) == 0 || n % (2 * a - 1) == a)
            cout << a << "," << a - 1 << "\n";
        if (n % (2 * a) == 0 || n % (2 * a) == a)
            cout << a << "," << a << "\n";
    }
}