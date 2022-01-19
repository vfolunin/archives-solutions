#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;

    vector<pair<int, int>> a(size);
    for (int i = 0; i < size; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    vector<int> b(size);
    for (int &x : b)
        cin >> x;

    sort(b.begin(), b.end());

    vector<int> res(size);
    for (int i = 0; i < size; i++)
        res[a[i].second] = b[i];

    for (int &x : res)
        cout << x << "\n";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}