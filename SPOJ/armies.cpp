#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int aSize;
    cin >> aSize;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;

    int bSize;
    cin >> bSize;

    vector<int> b(bSize);
    for (int &value : b)
        cin >> value;

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    if (a == b)
        cout << "Draw\n";
    else if (a < b)
        cout << "Megabajtolandia\n";
    else
        cout << "Bajtocja\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}