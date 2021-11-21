#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

bool solve() {
    vector<int> a(3);
    if (!(cin >> a[0] >> a[1] >> a[2]))
        return 0;

    sort(a.begin(), a.end());

    cout << "tripla";
    if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) {
        cout << " pitagorica";
        if (gcd(a[0], gcd(a[1], a[2])) == 1)
            cout << " primitiva";
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}