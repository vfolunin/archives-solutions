#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n < 0 || n > 100)
        cout << "X\n";
    else if (n < 50)
        cout << "F\n";
    else if (n < 60)
        cout << "D\n";
    else if (n < 70)
        cout << "C\n";
    else if (n < 80)
        cout << "B\n";
    else
        cout << "A\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}