#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int sum;
    cin >> sum;

    for (int count = 2; count * (count + 1) <= 2 * sum; count++) {
        if ((sum - count * (count + 1) / 2) % count == 0) {
            int from = (sum - count * (count + 1) / 2) / count + 1;
            cout << sum << " = " << from;
            for (int i = 1; i < count; i++)
                cout << " + " << from + i;
            cout << "\n";
            return;
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}