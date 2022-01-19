#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ssd(int base, int number) {
    int res = 0;
    while (number) {
        res += (number % base) * (number % base);
        number /= base;
    }
    return res;
}

void solve() {
    int test, base, number;
    cin >> test >> base >> number;

    cout << test << " " << ssd(base, number) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}