#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int an, bn, cn;
    string a, b, c;
    cin >> an >> bn >> cn >> a >> b >> c;

    double num = 0, den = an * bn * cn;
    for (char letter = 'A'; letter <= 'Z'; letter++) {
        int ak = count(a.begin(), a.end(), letter);
        int bk = count(b.begin(), b.end(), letter);
        int ck = count(c.begin(), c.end(), letter);
        num += ak * bk * ck * 34;
    }

    cout.precision(4);
    cout << fixed << num / den << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}