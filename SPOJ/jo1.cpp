#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    vector<int> a(6);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    if (!a.back())
        return 0;

    cout << (a[1] + a[2] + a[3] + a[4]) / 4.0 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}