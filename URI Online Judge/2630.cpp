#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string type;
    int r, g, b;
    cin >> type >> r >> g >> b;

    cout << "Caso #" << test << ": ";
    if (type == "min")
        cout << min(min(r, g), b);
    if (type == "max")
        cout << max(max(r, g), b);
    if (type == "mean")
        cout << (r + g + b) / 3;
    if (type == "eye")
        cout << (int)(0.30 * r + 0.59 * g + 0.11 * b);
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}