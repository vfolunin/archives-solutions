#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h, m, type;
    cin >> h >> m >> type;

    cout << setw(2) << setfill('0') << h << ":";
    cout << setw(2) << setfill('0') << m << " - A porta ";
    cout << (type ? "abriu!\n" : "fechou!\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}