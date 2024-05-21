#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    unordered_set<int> values;

    for (int i = 1; i * i <= n; i++)
        values.insert(i * i);

    for (int i = 1; i * i * i <= n; i++)
        values.insert(i * i * i);

    cout << values.size() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}