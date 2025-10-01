#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    for (int count5 = size, count3 = 0; count5 >= 0; count5--, count3++) {
        if (count5 % 3 == 0 && count3 % 5 == 0) {
            cout << string(count5, '5') << string(count3, '3') << "\n";
            return;
        }
    }

    cout << "-1\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}