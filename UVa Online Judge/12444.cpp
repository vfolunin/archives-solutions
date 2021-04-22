#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int conj, disj;
    cin >> conj >> disj;

    int a = 0, b = 0, turn = 0;
    for (int bit = 30; bit >= 0; bit--) {
        if (!(conj & (1 << bit)) && !(disj & (1 << bit))) {
            continue;
        } else if ((conj & (1 << bit)) && (disj & (1 << bit))) {
            a |= 1 << bit;
            b |= 1 << bit;
        } else if (!(conj & (1 << bit)) && (disj & (1 << bit))) {
            if (!turn) {
                a |= 1 << bit;
                turn = 1;
            } else {
                b |= 1 << bit;
            }
        } else {
            cout << "-1\n";
            return;
        }
    }

    if (a > b)
        swap(a, b);
    cout << a << " " << b << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}