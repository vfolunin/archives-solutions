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

    int count2 = 0, count5 = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        while (value % 2 == 0) {
            value /= 2;
            count2++;
        }
        while (value % 5 == 0) {
            value /= 5;
            count5++;
        }
    }

    cout << min(count2, count5) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}