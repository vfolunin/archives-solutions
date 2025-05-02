#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int value;
    cin >> value;

    if (value > 0)
        cout << 4 * value << " " << value * value << "\n";
    else
        cout << "the length of square's edge must be greater than 0\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}