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

    vector<double> a(4);
    for (double &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    if (abs(a[0] + a[1] + a[2] - a[3]) < 1e-9 ||
        abs(a[0] + a[3] - a[1] - a[2]) < 1e-9)
        cout << "YES\n";
    else
        cout << "NO\n";
}