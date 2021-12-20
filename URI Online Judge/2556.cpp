#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    if (!(cin >> size))
        return 0;

    vector<int> a(size);
    for (int &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    cout << size / 2 << " " << a[size / 2] - a[size / 2 - 1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}