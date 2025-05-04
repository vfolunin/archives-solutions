#include <iostream>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long double x;
        cin >> x;

        cout.precision(0);
        cout << fixed << x * (14 * x * x + 9 * x + 2) / 4 << "\n";
    }
}