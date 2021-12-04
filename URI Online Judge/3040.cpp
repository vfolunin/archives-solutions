#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h, d, b;
    cin >> h >> d >> b;

    if (200 <= h && h <= 300 && 50 <= d && 150 <= b)
        cout << "Sim\n";
    else
        cout << "Nao\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}