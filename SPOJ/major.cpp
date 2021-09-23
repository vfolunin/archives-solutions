#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    map<int, int> count;
    int mostFrequentItem = -1;

    for (int i = 0; i < n; i++) {
        int item;
        cin >> item;
        if (count[mostFrequentItem] < ++count[item])
            mostFrequentItem = item;
    }

    if (count[mostFrequentItem] * 2 > n)
        cout << "YES " << mostFrequentItem << "\n";
    else
        cout << "NO\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}