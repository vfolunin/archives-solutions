#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int year;
    cin >> year;

    cout << (year % 400 == 0 || year % 4 == 0 && year % 100) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}