#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> primePower(100);
    for (int i = 2; i <= n; i++) {
        int x = i;
        for (int p = 2; p * p <= x; p++) {
            while (x % p == 0) {
                primePower[p]++;
                x /= p;
            }
        }
        if (x > 1)
            primePower[x]++;
    }

    primePower.erase(remove(primePower.begin(), primePower.end(), 0), primePower.end());

    cout << setw(3) << n << "! =";
    for (int i = 0; i < primePower.size(); i++) {
        cout << setw(3) << primePower[i];
        if (i + 1 == primePower.size())
            cout << "\n";
        else if (i % 15 == 14)
            cout << "\n      ";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}