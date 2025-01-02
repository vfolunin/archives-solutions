#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, side;
    cin >> size >> side;

    if (size <= 0) {
        cout << "Number of sides must be positive\n";
    } else if (size < 3) {
        cout << "Need more sides\n";
    } else if (side <= 0) {
        cout << "Side length must be positive\n";
    } else {
        cout.precision(4);
        cout << fixed << size * side * side / (4 * tan(acos(-1) / size)) << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}