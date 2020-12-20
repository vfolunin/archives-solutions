#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int v, t;
    while (cin >> v >> t)
        cout << 2 * v * t << "\n";
}