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

    for (int i = 0; i < n; i++) {
        double a, b, c;
        cin >> a >> b >> c;

        cout.precision(1);
        cout << fixed << (2 * a + 3 * b + 5 * c) / 10 << "\n";
    }
}