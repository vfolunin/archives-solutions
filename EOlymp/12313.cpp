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

    long long count = 0, count2 = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count += value != 1;
        count2 += value == 2;
    }

    cout << count * (count - 1) / 2 - count2 * (count2 - 1) / 2 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}