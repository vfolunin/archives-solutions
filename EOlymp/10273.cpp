#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, divisor;
    cin >> size >> divisor;

    long long res = 1;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value % divisor == 0)
            res *= 2;
    }

    cout << res - 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}