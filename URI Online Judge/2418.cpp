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

    vector<double> a(5);
    for (double &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    cout.precision(1);
    cout << fixed << a[1] + a[2] + a[3] << "\n";
}