#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, queueCount, processTime;
    cin >> size >> queueCount >> processTime;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.rbegin(), a.rend());

    int res = 0;
    for (int i = 0; i < a.size(); i++)
        res = max(res, a[i] + (1 + i / queueCount) * processTime);

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}