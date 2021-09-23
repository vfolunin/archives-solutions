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

    while (n % 2 == 0) {
        int nextN = 0;
        while (n) {
            nextN = nextN * 2 + n % 2;
            n /= 2;
        }
        n = nextN;
    }

    cout << n << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}