#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long n, al, ar, bl, br;
    cin >> n >> al >> ar >> bl >> br;

    if (n <= ar) {
        cout << "A\n";
        return;
    }

    long long winL = 1, winR = ar;

    while (winR < n) {
        if (winL + br > winR + bl) {
            cout << "B\n";
            return;
        }

        winL += br + al;
        winR += bl + ar;
    }

    cout << (winL <= n && n <= winR ? "A\n" : "B\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}