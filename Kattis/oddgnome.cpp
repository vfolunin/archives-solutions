#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int gnomeCount;
    cin >> gnomeCount;

    vector<int> gnomes(gnomeCount);
    for (int &gnome : gnomes)
        cin >> gnome;

    for (int i = 1; i < gnomeCount; i++) {
        if (gnomes[i - 1] + 1 != gnomes[i]) {
            cout << i + 1 << "\n";
            break;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}