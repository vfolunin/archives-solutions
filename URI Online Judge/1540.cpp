#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long year1, consumption1, year2, consumption2;
    cin >> year1 >> consumption1 >> year2 >> consumption2;

    long long num = (consumption2 - consumption1) * 100;
    long long den = year2 - year1;
    long long ratio = num / den;

    cout << ratio / 100 << ",";
    cout << setw(2) << setfill('0') << ratio % 100 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}